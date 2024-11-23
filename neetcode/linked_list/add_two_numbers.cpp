/*
 * Add Two Numbers

 * You are given two non-empty linked lists, l1 and l2, where each represents a
 * non-negative integer.

 * The digits are stored in reverse order, e.g. the number 123 is represented as

 * 3 -> 2 -> 1 -> in the linked list.

 * Each of the nodes contains a single digit. You may assume the two numbers do
 not
 * contain any leading zero, except the number 0 itself.

 * Return the sum of the two numbers as a linked list.

 * Example 1:
 * Input: l1 = [1,2,3], l2 = [4,5,6]
 * Output: [5,7,9]
 * Explanation: 321 + 654 = 975.

 * Example 2:
 * Input: l1 = [9], l2 = [9]
 * Output: [8,1]
*/

#include "LinkedList.h"
#include <iostream>
#include <vector>
int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> list1(n);
  std::vector<int> list2(m);

  for (int i = 0; i < n; i++)
    std::cin >> list1[i];

  for (int i = 0; i < m; i++)
    std::cin >> list2[i];

  ListNode *head1 = createLinkedList(list1);
  ListNode *head2 = createLinkedList(list2);

  ListNode *l1 = head1, *l2 = head2;

  ListNode *d = new ListNode();
  ListNode *temp = d;

  int carry = 0;
  while (l1 != nullptr || l2 != nullptr || carry != 0) {
    int d1 = (l1 != nullptr) ? l1->val : 0;
    int d2 = (l2 != nullptr) ? l2->val : 0;

    int val = d1 + d2 + carry;
    carry = val / 10;
    val = val % 10;
    temp->next = new ListNode(val);
    temp = temp->next;

    l1 = (l1) ? l1->next : nullptr;
    l2 = (l2) ? l2->next : nullptr;
  }

  printLinkedList(d->next);

  return 0;
}
