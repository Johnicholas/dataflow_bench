#include "predicate_op.h"

#include <cassert>

// Constructor
PredicateOp::PredicateOp(int predicate, OpInterface* next) 
  : predicate_(predicate),
    next_(next)
{
  assert(next);
}

void PredicateOp::invoke(int t) {
  // TODO: same case
  next_->invoke(t);
}

