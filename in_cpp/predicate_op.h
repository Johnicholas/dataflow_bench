#ifndef DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_
#define DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_

#include "op_interface.h"

class PredicateOp : public OpInterface {
 public:
  // Constructor
  // Precondition: next is not null
  PredicateOp(int predicate, OpInterface* next);
  void invoke(int) override;

 private:
  int predicate_;
  OpInterface* next_;

};

#endif

