#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <vector>

struct Node {
  int data;
  Node *next;
  Node(int d, Node *n = nullptr) : data(d), next(n) {}
};

Node *createLL(const std::vector<int> arr);
void printLL(Node *head);
int getSizeOfLL(Node *head);
std::vector<int> getInputsForLL();
void loopHere(Node *head, Node *tail, int position);
Node *reverseLLRecursively(Node *head);

#endif // !LINKED_LIST_H
