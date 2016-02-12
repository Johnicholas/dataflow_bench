#include "op_interface.h"
#include "predicate_op.h"

class NullOp : public OpInterface {
public:
  void invoke(int) override {
  }
};

#include <gtest/gtest.h>

TEST(PredicateOpTest, PredicateOpCanBeCreated) {
  NullOp next;
  PredicateOp to_test(4, next);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

