/*
 * Merge K Sorted Linked Lists
* You are given an array of k linked lists lists, where each list is sorted in
ascending order.

* Return the sorted linked list that is the result of merging all of the
individual linked lists.

* Example 1:
* Input: lists = [[1,2,4],[1,3,5],[3,6]]
* Output: [1,1,2,3,3,4,5,6]

* Example 2:
* Input: lists = []
* Output: []

* Example 3:
* Input: lists = [[]]
* Output: []
*/

#include "LinkedList.h"
#include <iostream>
#include <vector>

std::vector<ListNode *>
createLinkedListVector(std::vector<std::vector<int>> &inputs) {
  std::vector<ListNode *> lists;
  for (auto list : inputs) {
    ListNode *head = createLinkedList(list);
    lists.push_back(head);
  }

  return lists;
}

ListNode *merge(ListNode *l1, ListNode *l2) {
  ListNode *dummy = new ListNode(-1);
  ListNode *temp = dummy;

  while (l1 && l2) {
    if (l1->val < l2->val) {
      temp->next = l1;
      l1 = l1->next;
    } else {
      temp->next = l2;
      l2 = l2->next;
    }
    temp = temp->next;
  }

  return dummy->next;
}

int main() {
  int k;
  std::cin >> k;
  std::vector<std::vector<int>> inputs(k);

  for (int i = 0; i < k; i++) {
    int n;
    std::cin >> n;
    std::vector<int> list;

    for (int j = 0; j < n; j++) {
      int num;
      std::cin >> num;
      list.push_back(num);
    }

    inputs.push_back(list);
  }

  std::vector<ListNode *> lists = createLinkedListVector(inputs);
  for (int i = 1; i < lists.size(); i++) {
    lists[i] = merge(lists[i], lists[i - 1]);
  }
  lists.back();

  return 0;
}
