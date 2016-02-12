// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/predicate_op.h"

#include <cassert>

// Constructor
PredicateOp::PredicateOp(int predicate, OpInterface* next)
  : predicate_(predicate),
    next_(next) {
  assert(next);
}

void PredicateOp::invoke(int incoming) {
  if (incoming != predicate_) {
    next_->invoke(incoming);
  }
}

