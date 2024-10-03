/*
 * Reorder Linked List

 * You are given the head of a singly linked-list.

 * The positions of a linked list of length = 7 for example, can intially be
 * represented as:

 * [0, 1, 2, 3, 4, 5, 6]

 * Reorder the nodes of the linked list to be in the following order:

 * [0, 6, 1, 5, 2, 4, 3]

 * Notice that in the general case for a list of length = n the nodes are
 reordered
 * to be in the following order:

 * [0, n-1, 1, n-2, 2, n-3, ...]

 * You may not modify the values in the list's nodes, but instead you must
 reorder
 * the nodes themselves.

 * Example 1:
 * Input: head = [2,4,6,8]
 * Output: [2,8,4,6]

 * Example 2:
 * Input: head = [2,4,6,8,10]
 * Output: [2,10,4,8,6]
*/
#include "LinkedList.h"
#include <iostream>
#include <vector>

ListNode *reverseLinkedList(ListNode *head) {
  ListNode *temp = head;
  ListNode *prev = nullptr;
  while (temp) {
    ListNode *nextNode = temp->next;
    temp->next = prev;
    prev = temp;
    temp = nextNode;
  }

  return prev;
}

void reOrderList(ListNode *head) {
  // split list in two
  ListNode *slow = head;
  ListNode *fast = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  fast = slow->next;
  slow->next = nullptr;
  // reverse the second list
  fast = reverseLinkedList(fast);

  ListNode *dummy = new ListNode();
  ListNode *l1 = head;
  ListNode *l2 = fast;
  ListNode *temp = dummy;
  while (l1 && l2) {
    temp->next = l1;
    l1 = l1->next;
    temp = temp->next;
    temp->next = l2;
    l2 = l2->next;
    temp = temp->next;
  }
  while (l1) {
    temp->next = l1;
    l1 = l1->next;
    temp = temp->next;
  }

  printLinkedList(dummy->next);
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> list(n);
  for (int i = 0; i < n; i++)
    std::cin >> list[i];

  ListNode *head = createLinkedList(list);
  printLinkedList(head);
  reOrderList(head);

  return 0;
}
