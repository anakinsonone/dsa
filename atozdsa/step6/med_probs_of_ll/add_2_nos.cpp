#include "LinkedList.h"
using namespace std;

int main() {
  Node *head1 = createLL(getInputsForLL());
  Node *head2 = createLL(getInputsForLL());

  int carry = 0;
  Node *temp1 = head1, *temp2 = head2;
  Node *newHead = new Node(-1), *newTemp = newHead, *newTail = nullptr;
  while (temp1 && temp2) {
    newTemp->data = temp1->data + temp2->data + carry;
    if (newTemp->data < 10) {
      carry = 0;
    } else {
      carry = 1;
      newTemp->data = newTemp->data % 10;
    }
    Node *nextTemp = new Node(-1);
    newTemp->next = nextTemp;
    newTail = newTemp;
    newTemp = nextTemp;
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  while (temp1) {
    newTemp->data = carry + temp1->data;
    if (newTemp->data < 10) {
      carry = 0;
    } else {
      carry = 1;
      newTemp->data = newTemp->data % 10;
    }
    Node *nextTemp = new Node(-1);
    newTemp->next = nextTemp;
    newTail = newTemp;
    newTemp = nextTemp;
    temp1 = temp1->next;
  }
  while (temp2) {
    newTemp->data = carry + temp2->data;
    if (newTemp->data < 10) {
      carry = 0;
    } else {
      carry = 1;
      newTemp->data = newTemp->data % 10;
    }
    Node *nextTemp = new Node(-1);
    newTemp->next = nextTemp;
    newTail = newTemp;
    newTemp = nextTemp;
    temp2 = temp2->next;
  }

  if (!carry) {
    newTail->next = nullptr;
  } else {
    newTemp->data = carry;
  }
  printLL(newHead);

  return 0;
}
