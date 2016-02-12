#ifndef DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_
#define DATAFLOW_BENCH_IN_CPP_PREDICATE_OP_H_

#include "op_interface.h"

class PredicateOp : public OpInterface {
 public:
  void invoke(int) override;

  // we need to store the int, right?
  // and the op?
};

#endif

