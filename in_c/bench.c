#include <stdio.h>
#include "table.h"
#include "arena.h"

struct Op;

typedef void (*op_invoke_func)(struct Op *op, int *t);

struct Op {
  struct Op* next;
  op_invoke_func invoke;
};

struct PredicateOp {
  struct Op op;
  int pred;
};

struct JoinOp {
  struct Op op;
  Table_T tbl;
};

struct ListNode {
  struct ListNode* next;
  int* t;
};

struct SinkOp {
  struct Op op;
  Arena_T pool;
  struct ListNode* list_head;
};

static void pred_op_invoke(struct Op* op, int* t);
static void join_op_invoke(struct Op* op, int* t);
static void sink_op_invoke(struct Op* op, int* t);

static struct Op* pred_op_init(Arena_T p, struct Op* next, int pred) {
  struct PredicateOp* result;

  result = Arena_alloc(p, sizeof(*result), __FILE__, __LINE__);
  result->op.next = next;
  result->op.invoke = pred_op_invoke;
  result->pred = pred;
  
  return (struct Op*) result;
}

static void pred_op_invoke(struct Op *op, int *t) {
  struct PredicateOp* self = (struct PredicateOp*) op;

  if (self->pred != *t) {
    struct Op* next = self->op.next;
    next->invoke(next, t);
  }
}

static struct Op* join_op_init(Arena_T p, struct Op *next) {
  struct JoinOp* result;
  int i;

  result = Arena_alloc(p, sizeof(*result), __FILE__, __LINE__);
  result->op.next = next;
  result->op.invoke = join_op_invoke;
  result->tbl = Table_new(0, 0, 0);
  
  for (i = 0; i < 12000; i++) {
    int* iptr;
    
    if (i % 2 != 0) {
      continue;
    }
    
    iptr = Arena_alloc(p, sizeof(*iptr), __FILE__, __LINE__);
    *iptr = i;
    Table_put(result->tbl, iptr, iptr);
  }

  return (struct Op*) result;
}

static void join_op_invoke(struct Op* op, int *t) {
  struct JoinOp* self = (struct JoinOp*) op;

  if (Table_get(self->tbl, t) == NULL) {
    struct Op* next = self->op.next;
    next->invoke(next, t);
  }
}

static struct Op* sink_op_init(Arena_T p) {
  struct SinkOp* result;

  result = Arena_alloc(p, sizeof(*result), __FILE__, __LINE__);
  result->op.next = NULL;
  result->op.invoke = sink_op_invoke;
  result->pool = p;
  result->list_head = NULL;
  
  return (struct Op*) result;
}

static void sink_op_invoke(struct Op* op, int* t) {
  struct SinkOp* self = (struct SinkOp*) op;
  struct ListNode* n;
  
  n = Arena_alloc(self->pool, sizeof(*n), __FILE__, __LINE__);
  n->next = self->list_head;
  n->t = t;
  self->list_head = n;
}

static int* intdup(Arena_T p, int i) {
  int* copy;
  
  copy = Arena_alloc(p, sizeof(*copy), __FILE__, __LINE__);
  *copy = i;
  return copy;
}

int main() {
  int i;
  
  for (i = 0; i < 10; i++) {
    Arena_T pool;
    struct Op *op;
    int j;
    // TODO: replace this
    // apr_time_t start_time;
    // start_time = apr_time_now();
    pool = Arena_new();
    
    op = sink_op_init(pool);
    op = pred_op_init(pool, op, 4);
    op = pred_op_init(pool, op, 6);
    op = join_op_init(pool, op);
    op = pred_op_init(pool, op, 8);
    op = pred_op_init(pool, op, 10);
    op = join_op_init(pool, op);

    for (j = 0; j < 2000000; j++) {
      if (j % 2 == 1) {
	op->invoke(op, intdup(pool, j));
      }
    }
    
    Arena_free(pool);
    // TODO: replace this
    // printf("Duration: %" APR_TIME_T_FMT " usec\n",
    // (apr_time_now() - start_time));
  }

  return 0;
}
