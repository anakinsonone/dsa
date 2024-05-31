#include "LinkedList.h"
using namespace std;

Node *reverseLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *temp = head;
  Node *prev = nullptr;
  while (temp) {
    Node *nextNode = temp->next;
    temp->next = prev;
    prev = temp;
    temp = nextNode;
  }
  return prev;
}

int main() {
  Node *head = createLL(getInputsForLL());

  head = reverseLL(head);

  int carry = 1;
  Node *temp = head;

  while (temp) {
    temp->data = temp->data + carry;
    if (temp->data < 10) {
      carry = 0;
      break;
    } else {
      carry = 1;
      temp->data = 0;
    }
    temp = temp->next;
  }
  head = reverseLL(head);
  if (carry) {
    Node *newHead = new Node(carry);
    head = newHead;
  }
  printLL(head);

  return 0;
}
