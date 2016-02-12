#include "predicate_op.h"

#include <cassert>

// Constructor
PredicateOp::PredicateOp(int predicate, OpInterface* next) 
  : predicate_(predicate),
    next_(next)
{
  assert(next);
}

void PredicateOp::invoke(int incoming) {
  if (incoming != predicate_) {
    next_->invoke(incoming);
  }
}

