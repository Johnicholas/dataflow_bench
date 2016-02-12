#ifndef DATAFLOW_BENCH_IN_CPP_JOIN_OP_H_
#define DATAFLOW_BENCH_IN_CPP_JOIN_OP_H_

#include "op_interface.h"

#include <set>

class JoinOp : public OpInterface {
 public:
  // Constructor
  // Precondition: next is not null
  JoinOp(std::set<int> table, OpInterface* next);

  void invoke(int) override;

 private:
  std::set<int> table_; // terrible name, improve?
  OpInterface* next_;

};

#endif

