// Copyright 2016 IDEXX
#include <math.h>
#include <stdio.h>
#include <time.h>
#include "dataflow_bench_in_cpp/benchmark.h"

int main(int argc, char* argv[]) {
  double SEC_PER_NS = pow(10.0, -9);
  for (int i = 0; i < 10; i += 1) {
    struct timespec start_time, finish_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    Benchmark b;
    b.Run();

    clock_gettime(CLOCK_MONOTONIC, &finish_time);
    double duration = finish_time.tv_sec - start_time.tv_sec;
    duration += (finish_time.tv_nsec - start_time.tv_nsec) * SEC_PER_NS;
    printf("Duration: %f seconds\n", duration);
  }
  return 0;
}
