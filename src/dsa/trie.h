#ifndef DSA_TRIE_H_
#define DSA_TRIE_H_

#include <initializer_list>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>

namespace dsa {

class Trie {
 public:
  Trie() = default;

  Trie(std::initializer_list<std::string_view> strs) noexcept {
    for (const std::string_view str : strs) {
      Insert(str);
    }
  }

  void Insert(const std::string_view str) noexcept {
    TrieNode *node = &head_;

    for (int i = 0; i < str.length(); ++i) {
      if (i == str.length() - 1) {
        node->is_end = true;
      }

      const char c = str[i];
      node = &node->children[c];
    }
  }

  [[nodiscard]]
  std::unordered_set<std::string> ToSet() const noexcept {
    std::unordered_set<std::string> strs;
    Traverse(&head_, "", strs);
    return strs;
  }

 private:
  struct TrieNode {
    bool is_end = false;
    std::unordered_map<char, TrieNode> children;
  };

  static void Traverse(const TrieNode *const node, const std::string &traversed,
                       std::unordered_set<std::string> &strs) noexcept {
    if (node->children.empty()) {
      return;
    }

    for (auto it = node->children.cbegin(); it != node->children.cend(); ++it) {
      const char c = it->first;
      const TrieNode *const next_node = &it->second;

      std::string traversed_clone = traversed;
      traversed_clone += c;

      if (node->is_end) {
        strs.emplace(traversed_clone);
      }

      Traverse(next_node, traversed_clone, strs);
    }
  }

  TrieNode head_;
};

}  // namespace dsa

#endif  // DSA_TRIE_H_
