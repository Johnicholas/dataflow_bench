#ifndef DATAFLOW_BENCH_IN_CPP_OP_INTERFACE_H_
#define DATAFLOW_BENCH_IN_CPP_OP_INTERFACE_H_

class OpInterface {
 public:
  virtual void invoke(int) = 0;

  // Destructor
  virtual ~OpInterface() {}
 protected:
  // Constructor
  OpInterface() {}

};

#endif
