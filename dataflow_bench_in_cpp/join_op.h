// Copyright 2016 IDEXX
#ifndef DATAFLOW_BENCH_IN_CPP_JOIN_OP_H_
#define DATAFLOW_BENCH_IN_CPP_JOIN_OP_H_

#include <set>

#include "dataflow_bench_in_cpp/op_interface.h"

class JoinOp : public OpInterface {
 public:
  // Constructor
  // Precondition: next is not null
  JoinOp(std::set<int> table, OpInterface* next);
  void invoke(int incoming) override;
 private:
  std::set<int> table_;  // terrible name, improve?
  OpInterface* next_;
};

#endif  // DATAFLOW_BENCH_IN_CPP_JOIN_OP_H_
