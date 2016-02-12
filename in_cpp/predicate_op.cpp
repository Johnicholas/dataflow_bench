#include "predicate_op.h"

// Constructor
PredicateOp::PredicateOp(int predicate, const OpInterface& next) 
  : predicate_(predicate),
    next_(next)
{
}

void PredicateOp::invoke(int x) {
  // TODO
}

