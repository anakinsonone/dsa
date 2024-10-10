#include "LinkedList.h"

ListNode *createLinkedList(std::vector<int> list) {
  ListNode *head = new ListNode(list[0]);
  if (list.size() == 1)
    return head;
  ListNode *temp = head;
  for (int i = 1; i < list.size(); i++) {
    ListNode *newNode = new ListNode(list[i]);
    temp->next = newNode;
    temp = newNode;
  }

  return head;
}

void printLinkedList(ListNode *head) {
  ListNode *temp = head;
  while (temp) {
    std::cout << temp->val << " -> ";
    temp = temp->next;
  }
  std::cout << '\n';
}
