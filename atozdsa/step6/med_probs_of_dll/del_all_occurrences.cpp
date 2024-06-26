#include "DoublyLinkedList.h"
#include <cstdlib>
using namespace std;

Node *removeAllInstances(Node *head, int key) {
  Node *temp = head;
  while (temp) {
    if (temp->data == key) {
      if (temp == head) {
        head = head->next;
      }

      Node *prevNode = temp->previous, *nextNode = temp->next;

      if (prevNode)
        prevNode->next = nextNode;
      if (nextNode)
        nextNode->previous = prevNode;

      free(temp);
      temp = nextNode;
    } else {
      temp = temp->next;
    }
  }
  return head;
}

int main() {
  Node *head = createDLL(getInputsForDLL());

  Node *newHead = removeAllInstances(head, 2);
  printDLL(newHead);

  return 0;
}
