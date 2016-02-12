#include "join_op.h"

// Constructor
JoinOp::JoinOp(std::set<int> table, OpInterface* next) :
  table_(table),
  next_(next)
{
}

void JoinOp::invoke(int incoming) {
  // TODO
}
