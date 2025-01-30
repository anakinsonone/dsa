/*
 * Reverse Nodes in K-Group
* You are given the head of a singly linked list head and a positive integer k.
* You must reverse the first k nodes in the linked list, and then reverse the
next
* k nodes, and so on. If there are fewer than k nodes left, leave the nodes as
they are.
* Return the modified list after reversing the nodes in each group of k.
* You are only allowed to modify the nodes' next pointers, not the values of the
nodes.

* Example 1:
* Input: head = [1,2,3,4,5,6], k = 3
* Output: [3,2,1,6,5,4]
*/

#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

ListNode *getKthNode(ListNode *curr, int k) {
  while (k > 0 && curr != NULL) {
    curr = curr->next;
    k--;
  }

  return curr;
}

int main() {
  int n, k;
  std::cin >> n;
  std::vector<int> input(n);
  for (int i = 0; i < n; i++) {
    std::cin >> input[i];
  }
  std::cin >> k;

  ListNode *head = createLinkedList(input);
  printLinkedList(head);

  ListNode *dummy = new ListNode(0, head);
  ListNode *groupPrev = dummy;

  while (true) {
    ListNode *kth = getKthNode(groupPrev, k);
    if (!kth) {
      break;
    }

    ListNode *groupNext = kth->next;

    ListNode *curr = groupPrev->next;
    ListNode *prev = kth->next;
    while (curr != groupNext) {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    ListNode *temp = groupPrev->next;
    groupPrev->next = kth;
    groupPrev = temp;
  }

  printLinkedList(dummy->next);

  return 0;
}
