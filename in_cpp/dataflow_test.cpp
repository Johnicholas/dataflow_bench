#include "op_interface.h"
#include "predicate_op.h"

class MockOp : public OpInterface {
public:
  void invoke(int incoming) override {
    saw_invoke_ = true;
    saw_which_ = incoming;
  }

  bool saw_invoke_ = false;
  int saw_which_;
};

#include <gtest/gtest.h>

TEST(PredicateOpTest, PredicateOpDelegatesToNextIfIncomingIsDifferent) {
  MockOp next;
  int some_integer = 4;
  PredicateOp to_test(some_integer, &next);
  int some_other_integer = 5;
  to_test.invoke(some_other_integer);
  EXPECT_TRUE(next.saw_invoke_);
  EXPECT_EQ(next.saw_which_, some_other_integer);
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

