#include "LinkedList.h"
using namespace std;

Node *findMiddle(Node *head) {
  Node *fast = head->next;
  Node *slow = head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

Node *mergeTwoLists(Node *list1Head, Node *list2Head) {
  Node *dummy = new Node(-1);
  Node *mover = dummy;

  while (list1Head != NULL && list2Head != NULL) {
    if (list1Head->data < list2Head->data) {
      mover->next = list1Head;
      mover = list1Head;
      list1Head = list1Head->next;
    } else {
      mover->next = list2Head;
      mover = list2Head;
      list2Head = list2Head->next;
    }
  }

  if (list1Head)
    mover->next = list1Head;
  else
    mover->next = list2Head;

  return dummy->next;
}

Node *sortLinkedList(Node *head) {
  if (head == NULL || head->next == NULL)
    return head;

  Node *middle = findMiddle(head);
  Node *left = head;
  Node *right = middle->next;
  middle->next = nullptr;

  left = sortLinkedList(left);
  right = sortLinkedList(right);
  return mergeTwoLists(left, right);
}

int main() {
  Node *head = createLL(getInputsForLL());

  Node *mid = findMiddle(head);

  head = sortLinkedList(head);
  printLL(head);

  return 0;
}
