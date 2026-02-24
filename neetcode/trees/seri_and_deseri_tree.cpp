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

#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "BinaryTree.h"

class Codec {
public:
  std::string serialize(BinaryTree::TreeNode<int> *root) {
    std::vector<std::string> res;
    dfsSerialize(root, res);
    return join(res, ",");
  }

  BinaryTree::TreeNode<int> *deserialize(std::string data) {
    std::vector<std::string> vals = split(data, ',');
    int i = 0;
    return dfsDeserialize(vals, i);
  }

private:
  void dfsSerialize(BinaryTree::TreeNode<int> *node,
                    std::vector<std::string> &res) {
    if (!node) {
      res.push_back("N");
      return;
    }

    res.push_back(std::to_string(node->value));
    dfsSerialize(node->left, res);
    dfsSerialize(node->right, res);
  }

  BinaryTree::TreeNode<int> *dfsDeserialize(std::vector<std::string> &vals,
                                            int &i) {
    if (vals[i] == "N") {
      i++;
      return nullptr;
    }

    BinaryTree::TreeNode<int> *node =
        new BinaryTree::TreeNode<int>(std::stoi(vals[i++]));
    node->left = dfsDeserialize(vals, i);
    node->right = dfsDeserialize(vals, i);
    return node;
  }

  std::string join(std::vector<std::string> &v, std::string delimiter) {
    std::ostringstream s;
    for (auto const &i : v) {
      if (&i != &v[0]) {
        s << delimiter;
      }
      s << i;
    }
    return s.str();
  }

  std::vector<std::string> split(const std::string &s, char delimiter) {
    std::vector<std::string> elems;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
      elems.push_back(item);
    }
    return elems;
  }
};

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

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printPretty(root);

  Codec c;
  std::string res = c.serialize(root);
  std::cout << res << '\n';
  BinaryTree::TreeNode<int> *d = c.deserialize(res);
  BinaryTree::printPretty(d);

  return 0;
}
