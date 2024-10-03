/*
 * Merge Two Sorted Linked Lists

 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists into one sorted linked list and return the head of the
 new
 * sorted linked list.
 *
 * The new list should be made up of nodes from list1 and list2.
 *
 * Example 1:
 * Input: list1 = [1,2,4], list2 = [1,3,5]
 * Output: [1,1,2,3,4,5]
 *
 * Example 2:
 * Input: list1 = [], list2 = [1,2]
 * Output: [1,2]
 *
 * Example 3:
 * Input: list1 = [], list2 = []
 * Output: []

*/
#include "LinkedList.h"
#include <cstddef>
#include <iostream>
#include <vector>

ListNode *mergeSortedLists(ListNode *list1, ListNode *list2) {
  ListNode *dummy = new ListNode();
  ListNode *temp = dummy;

  while (list1 && list2) {
    if (list1->val < list2->val) {
      temp->next = list1;
      list1 = list1->next;
    } else {
      temp->next = list2;
      list2 = list2->next;
    }
    temp = temp->next;
  }
  if (list1 != NULL) {
    temp->next = list1;
  } else if (list2 != NULL) {
    temp->next = list2;
  }
  return dummy->next;
}

int main() {
  int n1, n2;
  std::cin >> n1 >> n2;

  std::vector<int> nums1, nums2;
  for (int i = 0; i < n1; i++) {
    int num;
    std::cin >> num;
    nums1.push_back(num);
  }
  for (int i = 0; i < n2; i++) {
    int num;
    std::cin >> num;
    nums2.push_back(num);
  }

  ListNode *head1 = createLinkedList(nums1);
  ListNode *head2 = createLinkedList(nums2);
  printLinkedList(head1);
  printLinkedList(head2);

  ListNode *mergedHead = mergeSortedLists(head1, head2);
  printLinkedList(mergedHead);

  return 0;
}
