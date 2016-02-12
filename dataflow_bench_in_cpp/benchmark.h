// Copyright 2016 IDEXX
#ifndef DATAFLOW_BENCH_IN_CPP_BENCHMARK_H_
#define DATAFLOW_BENCH_IN_CPP_BENCHMARK_H_

#include "dataflow_bench_in_cpp/sink_op.h"
#include "dataflow_bench_in_cpp/predicate_op.h"
#include "dataflow_bench_in_cpp/join_op.h"

class Benchmark {
 public:
  // Constructor
  Benchmark();
 private:
  SinkOp sink;
  PredicateOp p4;
  PredicateOp p6;
  JoinOp j1;
  PredicateOp p8;
  PredicateOp p10;
  JoinOp j2;
};

#endif  // DATAFLOW_BENCH_IN_CPP_BENCHMARK_H_
