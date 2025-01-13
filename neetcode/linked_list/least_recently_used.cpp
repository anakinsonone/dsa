/*
 * Implement the Least Recently Used (LRU) cache class LRUCache. The class
should support the following operations

* - LRUCache(int capacity) Initialize the LRU cache of size capacity.
* - int get(int key) Return the value cooresponding to the key if the key
exists, otherwise return -1.
* - void put(int key, int value) Update the value of
the key if the key exists. Otherwise, add the key-value pair to the cache. If
the introduction of the new pair causes the cache to exceed its capacity, remove
the least recently used key.

* A key is considered used if a get or a put operation is
called on it.

* Ensure that get and put each run in O(1) average time complexity.
 * */

class Node {
public:
  int key;
  int val;
  Node *prev;
  Node *next;

  Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

#include <unordered_map>
class LRUCache {
private:
  int cap;
  std::unordered_map<int, Node *> cache;
  Node *left;
  Node *right;

  void remove(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
  }

  void insert(Node *node) {
    Node *prev = right->prev;
    prev->next = node;
    node->prev = prev;
    node->next = right;
    right->prev = node;
  }

public:
  LRUCache(int capacity) {
    cap = capacity;
    cache.clear();
    left = new Node(0, 0);
    right = new Node(0, 0);
    left->next = right;
    right->prev = left;
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      Node *node = cache[key];
      remove(node);
      insert(node);
      return node->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      remove(cache[key]);
    }
    Node *newNode = new Node(key, value);
    cache[key] = newNode;
    insert(newNode);

    if (cache.size() > cap) {
      Node *lru = left->next;
      remove(lru);
      cache.erase(lru->key);
      delete lru;
    }
  }
};
