/*
 * 297. Serialize and Deserialize Binary Tree

 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in the
 * same or another computer environment.

 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.

 * Clarification: The input/output format is the same as how LeetCode serializes
 * a binary tree. You do not necessarily need to follow this format, so please
 * be creative and come up with different approaches yourself.

 * Example 1:
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]

 * Example 2:
 * Input: root = []
 * Output: []

 * Constraints:
 * The number of nodes in the tree is in the range [0, 104].
 * -1000 <= Node.val <= 1000
 */

#include <deque>
#include <iostream>
#include <optional>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#include "BinaryTree.h"

std::string join(const std::vector<std::string>& v, char delim) {
  std::ostringstream s;
  for (const auto& i : v) {
    if (&i != &v[0]) s << delim;
    s << i;
  }

  return s.str();
}

BinaryTree::TreeNode<int>

void dfsSerialize(BinaryTree::TreeNode<int>* root,
                  std::vector<std::string>& res) {
  if (!root) {
    res.push_back("N");
    return;
  }

  res.push_back(std::to_string(root->value));
  dfsSerialize(root->left, res);
  dfsSerialize(root->right, res);
}

std::string serialize(BinaryTree::TreeNode<int>* root) {
  std::vector<std::string> res;
  dfsSerialize(root, res);
  return join(res, ',');
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -1001) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printPretty(root);

  std::string res = serialize(root);
  std::cout << res;

  return 0;
}
