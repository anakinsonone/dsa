#ifndef TRIE
#define TRIE

#include <vector>
namespace Trie {
class TrieNode {
 public:
  std::vector<TrieNode*> children;
  bool word;

  TrieNode() : children(26, nullptr), word(false) {}
};
}  // namespace Trie

#endif  // !TRIE
