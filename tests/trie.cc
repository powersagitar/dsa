#include <dsa/trie.h>
#include <gtest/gtest.h>

#include <string>
#include <unordered_set>

TEST(Trie, Empty) {
  dsa::Trie trie;

  std::unordered_set<std::string> expected_trie;

  EXPECT_EQ(trie.ToSet(), expected_trie);
}

TEST(Trie, InitializerList) {
  dsa::Trie trie{"hel", "hello", "wor", "world"};

  std::unordered_set<std::string> expected_trie{"hel", "hello", "wor", "world"};

  EXPECT_EQ(trie.ToSet(), expected_trie);
}

TEST(Trie, Insert) {
  dsa::Trie trie;

  trie.Insert("hel");
  trie.Insert("hello");
  trie.Insert("wor");
  trie.Insert("world");

  std::unordered_set<std::string> expected_trie{"hel", "hello", "wor", "world"};

  EXPECT_EQ(trie.ToSet(), expected_trie);
}

TEST(Trie, Random) {
  dsa::Trie trie{"zom", "zor", "zob", "zoc", "bor", "bom", "boo", "baz"};

  std::unordered_set<std::string> expected{"zom", "zor", "zob", "zoc",
                                           "bor", "bom", "boo", "baz"};

  EXPECT_EQ(trie.ToSet(), expected);
}
