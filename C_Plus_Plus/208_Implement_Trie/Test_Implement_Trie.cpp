#include <gtest/gtest.h>
#include "Implement_Trie.cpp"

class TrieTests : public ::testing::Test {

    protected:
        Trie sut;
};

TEST_F(TrieTests, StartsWithReturnsTrue)
{
    sut.insert("apple");
    ASSERT_TRUE(sut.startsWith("app"));
}