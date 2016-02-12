// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/sink_op.h"

// Constructor
SinkOp::SinkOp()
  : list_() {
  list_.reserve(1000000);
}

void SinkOp::Invoke(int incoming) {
  list_.push_back(incoming);
}
