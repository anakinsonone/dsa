/*
 * Reverse a Linked List

 * Given the beginning of a singly linked list head, reverse the list, and
 return
 * the new beginning of the list.

 * Example 1:
 * Input: head = [0,1,2,3]
 * Output: [3,2,1,0]

 * Example 2:
 * Input: head = []
 * Output: []
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

int main() {
  int n;
  std::cin >> n;
  std::vector<int> list(n);
  for (int i = 0; i < n; i++)
    std::cin >> list[i];

  ListNode *head = createLinkedList(list);
  printLinkedList(head);
  std::cout << '\n';
  ListNode *revHead = reverseLinkedList(head);
  printLinkedList(revHead);

  return 0;
}
