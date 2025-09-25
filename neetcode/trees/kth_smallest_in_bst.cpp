/*
 * Given the root of a binary search tree, and an integer k, return the kth
 * smallest value (1-indexed) in the tree.

 * A binary search tree satisfies the following constraints:

 * The left subtree of every node contains only nodes with keys less than the
 * node's key. The right subtree of every node contains only nodes with keys
 * greater than the node's key. Both the left and right subtrees are also binary
 * search trees.

 * Example 1:
 * Input: root = [2,1,3], k = 1
 * Output: 1

 * Example 2:
 * Input: root = [4,3,5,2,null], k = 4
 * Output: 5

 * Constraints:
 * 1 <= k <= The number of nodes in the tree <= 1000.
 * 0 <= Node.val <= 1000
*/

#include <deque>
#include <iostream>
#include <optional>
#include <set>
#include <vector>

#include "BinaryTree.h"

std::set<int> allNodeValues(BinaryTree::TreeNode<int>* root) {
  std::set<int> st;
  std::deque<BinaryTree::TreeNode<int>*> dq;
  dq.push_back(root);

  while (!dq.empty()) {
    BinaryTree::TreeNode<int>* curr = dq.front();
    dq.pop_front();

    st.insert(curr->value);

    if (curr->left) dq.push_back(curr->left);
    if (curr->right) dq.push_back(curr->right);
  }

  return st;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    if (num == -1) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = num;
    }
  }

  BinaryTree::TreeNode<int>* root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::set<int> nodeSet = allNodeValues(root);
  int c = 1;
  for (int i : nodeSet) {
    if (c == k) {
      std::cout << i << '\n';
      break;
    }
    c++;
  }

  return 0;
}
