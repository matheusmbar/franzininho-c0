#include <iostream>

#include "CppUTest/TestHarness.h"

TEST_GROUP(FirstTestGroup){
    // void setup(){}
    // void teardown(){}
};

// TEST(FirstTestGroup, FirstTestFail) {
//   FAIL("Fail me!");
// }

TEST(FirstTestGroup, FirstTest) {
  CHECK(0 == 0);
}

TEST(FirstTestGroup, Sizeof32) {
  CHECK_EQUAL(sizeof(uint32_t), sizeof(uint32_t*));
}