/*Given the root of a binary tree, return its depth.
 * The depth of a binary tree is defined as the number of nodes along the
 * longest path from the root node down to the farthest leaf node.
 * Example 1:
 * Input: root = [1,2,3,null,null,4]
 * Output: 3

 * Example 2:
 * Input: root = []
 * Output: 0
 */
#include "BinaryTree.h"
#include <algorithm>
#include <deque>
#include <iostream>
#include <optional>
#include <stack>
#include <utility>
#include <vector>

int treeDepth(BinaryTree::TreeNode<int> *root) {
  if (!root)
    return 0;
  // recursion
  // return 1 + std::max(treeDepth(root->left), treeDepth(root->right));

  int level = 1;
  // BFS
  // int level = 0;
  // std::deque<BinaryTree::TreeNode<int> *> dq;
  // dq.push_back(root);
  //
  // while (!dq.empty()) {
  //   int size = dq.size();
  //   for (int i = 0; i < size; i++) {
  //     BinaryTree::TreeNode<int> *current = dq.front();
  //     dq.pop_front();
  //
  //     if (current->left)
  //       dq.push_back(current->left);
  //     if (current->right)
  //       dq.push_back(current->right);
  //   }
  //   level++;
  // }

  // DFS
  std::stack<std::pair<BinaryTree::TreeNode<int> *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    BinaryTree::TreeNode<int> *current = st.top().first;
    int l = st.top().second;
    st.pop();

    if (current) {
      level = std::max(level, l);
      if (current->left)
        st.push({current->left, l + 1});
      if (current->right)
        st.push({current->right, l + 1});
    }
  }

  return level;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::optional<int>> nums(n);
  for (int i = 0; i < n; i++) {
    int val;
    std::cin >> val;
    if (val == -101) {
      nums[i] = std::nullopt;
    } else {
      nums[i] = val;
    }
  }

  BinaryTree::TreeNode<int> *root = BinaryTree::createBinaryTree(nums);
  BinaryTree::printBinaryTree(root);

  std::cout << "depth: " << treeDepth(root);

  return 0;
}
