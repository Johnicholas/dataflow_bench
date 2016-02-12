#include "op_interface.h"
#include "predicate_op.h"

#include <gtest/gtest.h>

TEST(PredicateOpTest, PredicateOpCanBeCreated) {
  PredicateOp to_test;
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

