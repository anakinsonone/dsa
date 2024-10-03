/*
* Remove Node From End of Linked List

 * You are given the beginning of a linked list head, and an integer n.

 * Remove the nth node from the end of the list and return the beginning of the
 * list.

 * Example 1:
 * Input: head = [1,2,3,4], n = 2
 * Output: [1,2,4]

 * Example 2:
 * Input: head = [5], n = 1
 * Output: []

 * Example 3:
 * Input: head = [1,2], n = 2
 * Output: [2]
*/

#include "LinkedList.h"
#include <iostream>
#include <vector>

ListNode *removeNthFromEnd(ListNode *head, int n) {
  ListNode *temp = head;
  int count = 0;
  while (temp) {
    count++;
    temp = temp->next;
  }

  if (n == count)
    return head->next;

  int num = count - n;
  temp = head;
  ListNode *prev = nullptr;
  while (num) {
    prev = temp;
    temp = temp->next;
    num--;
  }
  prev->next = prev->next->next;
  return head;
}

int main() {
  int size, n;
  std::cin >> size >> n;
  std::vector<int> list(size);
  for (int i = 0; i < size; i++)
    std::cin >> list[i];

  ListNode *head = createLinkedList(list);
  ListNode *temp = removeNthFromEnd(head, 2);
  printLinkedList(temp);

  return 0;
}
