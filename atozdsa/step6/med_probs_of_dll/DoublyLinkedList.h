#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <cstddef>
#include <iostream>
#include <vector>

struct Node {
  int data;
  Node *next;
  Node *previous;
  Node(int d, Node *n = nullptr, Node *p = nullptr)
      : data(d), next(n), previous(p) {}
};
std::vector<int> getInputsForDLL();
Node *createDLL(std::vector<int> arr);
void printDLL(Node *head);
Node *reverseDLL(Node *head);
int getLengthOfDLL(Node *head);

#endif // !DOUBLY_LINKED_LIST
