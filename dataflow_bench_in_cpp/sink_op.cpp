// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/sink_op.h"

// Constructor
SinkOp::SinkOp()
  : list_() {
}

void SinkOp::invoke(int incoming) {
  list_.push_back(incoming);
}
