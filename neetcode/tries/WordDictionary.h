#ifndef WORDDICTIONARY
#define WORDDICTIONARY

#include <string>

#include "Trie.h"

namespace WordDictionary {

class WordDictionary {
  Trie::TrieNode* root;

 public:
  WordDictionary() { root = new Trie::TrieNode(); }

  void insert(std::string word) {
    Trie::TrieNode* curr = root;
    for (char w : word) {
      int idx = w - 'a';
      if (curr->children[idx] == nullptr) {
        curr->children[idx] = new Trie::TrieNode();
      }
      curr = curr->children[idx];
    }
    curr->word = true;
  }

  bool search(std::string word) {
    Trie::TrieNode* curr = root;
    for (char w : word) {
      int i = w - 'a';
      if (curr->children[i] == nullptr) {
        return false;
      }
      curr = curr->children[i];
    }
    return curr->word;
  }
};
}  // namespace WordDictionary

#endif  // !WORDDICTIONARY
