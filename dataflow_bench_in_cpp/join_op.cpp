// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/join_op.h"
#include <cassert>
#include <set>

// Constructor
JoinOp::JoinOp(OpInterface* next) :
  table_(),
  next_(next) {
  assert(next);
}

void JoinOp::Add(int to_add) {
  table_.insert(to_add);
}

void JoinOp::Invoke(int incoming) {
  if (table_.count(incoming) == 0) {
    next_->Invoke(incoming);
  }
}
