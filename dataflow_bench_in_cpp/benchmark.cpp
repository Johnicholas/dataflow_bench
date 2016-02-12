// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/benchmark.h"
#include <set>

// Constructor
Benchmark::Benchmark()
  : sink(),
    p4(4, &sink),
    p6(6, &p4),
    j1(&p6),
    p8(8, &j1),
    p10(10, &p8),
    j2(&p10) {
  for (int i = 0; i < 12000; i += 1) {
    if (i%2 == 0) {
      j1.Add(i);
      j2.Add(i);
    }
  }
}

void Benchmark::Run() {
  for (int i = 0; i < 2000000; i += 1) {
    if (i%2 == 1) {
      j2.Invoke(i);
    }
  }
}

