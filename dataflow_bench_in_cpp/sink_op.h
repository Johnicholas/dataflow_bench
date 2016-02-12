// Copyright 2016 IDEXX
#ifndef DATAFLOW_BENCH_IN_CPP_SINK_OP_H_
#define DATAFLOW_BENCH_IN_CPP_SINK_OP_H_

#include <vector>
#include "dataflow_bench_in_cpp/op_interface.h"

class SinkOp : public OpInterface {
 public:
  // Constructor
  SinkOp();
  void Invoke(int incoming) override;
 private:
  std::vector<int> list_;  // terrible name, improve?
};

#endif  // DATAFLOW_BENCH_IN_CPP_SINK_OP_H_
