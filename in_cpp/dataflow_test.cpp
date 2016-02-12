#include "op_interface.h"
#include "predicate_op.h"
#include "join_op.h"

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

TEST(PredicateOpTest, PredicateOpFiltersOutIntegersEqualToItsPredicate) {
  for (int i = 0; i < 10; i += 1) {
    MockOp next;
    PredicateOp to_test(i, &next);
    for (int j = 0; j < 10; j += 1) {
      to_test.invoke(j);
      if (i == j) {
	EXPECT_FALSE(next.saw_invoke_);
      } else {
	EXPECT_TRUE(next.saw_invoke_);
	EXPECT_EQ(next.saw_which_, j);
      }
      next.saw_invoke_ = false;
    }
  }
}

TEST(JoinOpTest, JoinOpFiltersOutIntegersThatAreInItsTable) {
  MockOp next;
  std::set<int> some_evens_below_ten = { 0, 2, 4, 6, 8 };
  JoinOp to_test(some_evens_below_ten, &next);
  for (int i = 0; i < 10; i += 1) {
    to_test.invoke(i);
    if (i%2 == 0) {
      EXPECT_FALSE(next.saw_invoke_);
    } else {
      EXPECT_TRUE(next.saw_invoke_);
      EXPECT_EQ(next.saw_which_, i);
    }
    next.saw_invoke_ = false;
  }
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

