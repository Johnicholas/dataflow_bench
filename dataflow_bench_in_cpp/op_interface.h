// Copyright 2016 IDEXX
#ifndef DATAFLOW_BENCH_IN_CPP_OP_INTERFACE_H_
#define DATAFLOW_BENCH_IN_CPP_OP_INTERFACE_H_

class OpInterface {
 public:
  virtual void Invoke(int incoming) = 0;
  // Destructor
  virtual ~OpInterface() {}
 protected:
  // Constructor
  OpInterface() {}
};

#endif  // DATAFLOW_BENCH_IN_CPP_OP_INTERFACE_H_
