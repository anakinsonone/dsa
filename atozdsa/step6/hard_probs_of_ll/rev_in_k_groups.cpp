#include "LinkedList.h"
using namespace std;

Node *reversell(Node *head) {
  Node *temp = head;
  Node *prevNode = NULL;
  while (temp) {
    Node *nextNode = temp->next;

    temp->next = prevNode;

    prevNode = temp;
    temp = nextNode;
  }
  return prevNode;
}

Node *getkthnode(Node *temp, int k) {
  k -= 1;

  while (temp != NULL && k > 0) {
    k--;
    temp = temp->next;
  }
  return temp;
}

Node *reversek(Node *head, int k) {
  Node *temp = head;
  Node *prevLast = NULL;

  while (temp) {
    Node *kthnode = getkthnode(temp, k);

    if (kthnode == NULL) {
      if (prevLast) {
        prevLast->next = temp;
      }
      break;
    }

    Node *nextNode = kthnode->next;
    kthnode->next = NULL;

    reversell(temp);

    if (temp == head) {
      head = kthnode;
    } else {
      prevLast->next = kthnode;
    }

    prevLast = temp;
    temp = nextNode;
  }

  return head;
}

int main() {
  Node *head = createLL(getInputsForLL());
  int k;
  cin >> k;

  head = reversek(head, k);
  printLL(head);

  return 0;
}
