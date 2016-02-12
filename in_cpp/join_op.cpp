#include "join_op.h"
#include <cassert>

// Constructor
JoinOp::JoinOp(std::set<int> table, OpInterface* next) :
  table_(table),
  next_(next)
{
  assert(next);
}

void JoinOp::invoke(int incoming) {
  if (table_.count(incoming) == 0) {
    next_->invoke(incoming);
  }
}
