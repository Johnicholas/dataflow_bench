// Copyright 2016 IDEXX
#include "dataflow_bench_in_cpp/benchmark.h"
#include <set>

// Constructor
Benchmark::Benchmark()
  : sink(),
    p4(4, &sink),
    p6(6, &p4),
    j1(std::set<int>{ 2, 4, 6, 8 }, &p6),
    p8(8, &j1),
    p10(10, &p8),
    j2(std::set<int>{ 2, 4, 6, 8 }, &p10) {
}
