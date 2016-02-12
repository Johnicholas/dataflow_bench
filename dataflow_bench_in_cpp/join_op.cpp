// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/join_op.h"
#include <cassert>
#include <set>

// Constructor
JoinOp::JoinOp(std::set<int> table, OpInterface* next) :
  table_(table),
  next_(next) {
  assert(next);
}

void JoinOp::invoke(int incoming) {
  if (table_.count(incoming) == 0) {
    next_->invoke(incoming);
  }
}
