/*
 * Add Two Numbers

 * You are given two non-empty linked lists, l1 and l2, where each represents a
 * non-negative integer.

 * The digits are stored in reverse order, e.g. the number 123 is represented as
 3
 * -> 2 -> 1 -> in the linked list.

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
  std::vector<int> l1(n);
  std::vector<int> l2(m);

  for (int i = 0; i < n; i++)
    std::cin >> l1[i];

  for (int i = 0; i < m; i++)
    std::cin >> l2[i];

  ListNode *head1 = createLinkedList(l1);
  ListNode *head2 = createLinkedList(l2);

  printLinkedList(head1);
  printLinkedList(head2);

  int num1 = 0, num2 = 0, pow = 1;
  ListNode *temp = head1;
  while (temp) {
    num1 += temp->val * pow;
    temp = temp->next;
    pow *= 10;
  }

  temp = head2;
  pow = 1;
  while (temp) {
    num2 += temp->val * pow;
    temp = temp->next;
    pow *= 10;
  }

  std::cout << "num1: " << num1 << '\n' << "num2: " << num2;
  int sum = num1 + num2;
  std::cout << '\n' << "sum: " << sum;

  std::vector<int> res;
  while (sum >= 0) {
    int digit = sum % 10;
    res.push_back(digit);
    sum = sum / 10;
    if (sum == 0)
      break;
  }
  ListNode *resHead = createLinkedList(res);
  std::cout << '\n';
  printLinkedList(resHead);

  return 0;
}
