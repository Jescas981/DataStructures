#include <gtest/gtest.h>

#include <adt/array_list.hpp>
#include <adt/array_list.ipp>
#include <iostream>

struct ArrayListFixture : testing::Test {
  ADT::ArrayList<float>* array;
  void SetUp() override { array = new ADT::ArrayList<float>({5, 3, 2, 1}); }
  void TearDown() override {}
};

TEST_F(ArrayListFixture, Basic) {
  ASSERT_EQ(array->size(), 4);
  ASSERT_EQ(array->capacity(), 4);
  // Increase capacity size
  array->Add(5);
  array->Add(6);
  array->Append(10);
  ASSERT_EQ(array->size(), 7);
  ASSERT_EQ(array->capacity(), 12);
  // Derease capacity size
  array->Remove(array->begin());
  array->Remove(array->begin() + 1);
  array->Remove(array->begin() + 2);
  ASSERT_EQ(array->size(), 4);
  ASSERT_EQ(array->capacity(), 4);
  // Only arithmetic types
  EXPECT_EQ(array->Sum(), 27);
  // EXPECT_NEAR(array->Average(), 4.57, 0.01);
}

TEST_F(ArrayListFixture, Search) {}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}