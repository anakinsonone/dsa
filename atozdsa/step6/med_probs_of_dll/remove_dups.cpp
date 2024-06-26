#include "DoublyLinkedList.h"
using namespace std;

int main() {
  Node *head = createDLL(getInputsForDLL());

  Node *temp = head;
  while (temp && temp->next) {
    Node *nextNode = temp->next;
    while (nextNode && nextNode->data == temp->data) {
      nextNode = nextNode->next;
    }
    temp->next = nextNode;
    if (nextNode) {
      nextNode->previous = temp;
    }
    temp = temp->next;
  }

  printDLL(head);

  return 0;
}
