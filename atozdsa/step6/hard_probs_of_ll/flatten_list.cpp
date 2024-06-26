#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node *bottom;
  Node() : data(0), next(nullptr), bottom(nullptr) {};
  Node(int d) : data(d), next(nullptr), bottom(nullptr) {};
  Node(int d, Node *n, Node *b) : data(d), next(n), bottom(b) {};
};

Node *merge(Node *list1, Node *list2) {
  Node *dummyNode = new Node(-1);
  Node *res = dummyNode;

  while (list1 != NULL && list2 != NULL) {
    if (list1->data < list2->data) {
      res->bottom = list1;
      res = list1;
      list1 = list1->bottom;
    } else {
      res->bottom = list2;
      res = list2;
      list2 = list2->bottom;
    }
    res->next = NULL;
  }

  if (list1) {
    res->bottom = list1;
  } else {
    res->bottom = list2;
  }

  if (dummyNode->bottom) {
    dummyNode->bottom->next = NULL;
  }

  return dummyNode->bottom;
}

Node *flattenList(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *mergeHead = flattenList(head->next);
  head = merge(head, mergeHead);
  return head;
}

int main() {
  Node *head = new Node(5);
  head->bottom = new Node(14);

  head->next = new Node(4);
  head->next->bottom = new Node(10);

  head->next->next = new Node(12);
  head->next->next->bottom = new Node(13);
  head->next->next->bottom->bottom = new Node(20);

  head->next->next->next = new Node(7);
  head->next->next->next->bottom = new Node(17);

  Node *flattened = flattenList(head);
  Node *temp = flattened;

  while (temp) {
    cout << temp->data << " -> ";
    temp = temp->bottom;
  }

  return 0;
}
