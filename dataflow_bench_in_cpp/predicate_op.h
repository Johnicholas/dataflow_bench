// Copyright 2016 IDEXX
#ifndef DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_
#define DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_

#include "dataflow_bench_in_cpp/op_interface.h"

class PredicateOp : public OpInterface {
 public:
  // Constructor
  // Precondition: next is not null
  PredicateOp(int predicate, OpInterface* next);
  void Invoke(int incoming) override;
 private:
  int predicate_;
  OpInterface* next_;
};

#endif  // DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_
