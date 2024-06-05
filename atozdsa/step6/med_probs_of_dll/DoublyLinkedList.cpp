#include "DoublyLinkedList.h"
using namespace std;

vector<int> getInputsForDLL() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  return arr;
}

Node *createDLL(vector<int> arr) {
  Node *head = new Node(arr[0]);
  Node *prev = head;
  for (int i = 1; i < arr.size(); i++) {
    Node *temp = new Node(arr[i], nullptr, prev);
    prev->next = temp;
    prev = temp;
  }
  return head;
}

void printDLL(Node *head) {
  Node *temp = head;
  while (temp) {
    cout << temp->data << " <=> ";
    temp = temp->next;
  }
  cout << '\n';
}

Node *deleteHead(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node *prev = head;
  head = head->next;

  head->previous = nullptr;
  prev->next = nullptr;
  delete prev;
  return head;
}

Node *deleteTail(Node *head) {
  if (head == NULL || head->next == NULL) {
    return NULL;
  }

  Node *temp = head;
  while (temp->next) {
    temp = temp->next;
  }
  Node *prev = temp->previous;
  temp->previous = nullptr;

  delete temp;
  prev->next = nullptr;

  return head;
}

Node *deleteKthNode(Node *head, int k) {
  int count = 0;
  Node *temp = head;
  while (temp) {
    count++;
    if (count == k)
      break;
    temp = temp->next;
  }
  Node *prev = temp->previous;
  Node *next = temp->next;

  if (prev == NULL && next == NULL) {
    delete temp;
    return NULL;
  } else if (prev == NULL) {
    return deleteHead(head);
  } else if (next == NULL) {
    return deleteTail(head);
  } else {
    prev->next = next;
    next->previous = prev;
    delete temp;
    return head;
  }
}

void deleteNode(Node *node) {
  Node *prev = node->previous;
  Node *next = node->next;

  if (next == NULL) {
    prev->next = nullptr;
    node->previous = nullptr;
    delete node;
    return;
  }

  prev->next = next;
  next->previous = prev;
  node->previous = node->next = nullptr;
  delete node;
}

Node *insertBeforeHead(Node *head, int val) {
  Node *newHead = new Node(val, head);
  head->previous = newHead;

  return newHead;
}

void insertAfterHead(Node *head, int val) {
  Node *newNode = new Node(val, head->next, head);
  head->next = newNode;
  newNode->next->previous = newNode;
}

void insertBeforeTail(Node *head, int val) {
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newNode = new Node(val, temp, temp->previous);
  temp->previous = newNode;
  newNode->previous->next = newNode;
}

void insertAfterTail(Node *head, int val) {
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  Node *newTail = new Node(val, nullptr, temp);
  temp->next = newTail;
}
void insertAfterKth(Node *head, int val, int k) {
  int count = 0;
  Node *temp = head;
  while (temp->next != NULL) {
    count++;
    if (count == k)
      break;
    temp = temp->next;
  }
  Node *next = temp->next;
  Node *newNode = new Node(val, next, temp);
  temp->next = newNode;
  next->previous = newNode;
}

void insertBeforeKth(Node *head, int val, int k) {
  int count = 0;
  Node *temp = head;
  while (temp->next != NULL) {
    count++;
    if (count == k)
      break;
    temp = temp->next;
  }
  Node *prev = temp->previous;
  Node *newNode = new Node(val, temp, prev);
  temp->previous = newNode;
  prev->next = newNode;
}

void insertBeforeNode(Node *node, int val) {
  Node *prev = node->previous;
  Node *newNode = new Node(val, node, prev);
  prev->next = newNode;
  node->previous = newNode;
}

void insertAfterNode(Node *node, int val) {
  Node *next = node->next;
  Node *newNode = new Node(val, next, node);
  next->previous = newNode;
  node->next = newNode;
}

Node *reverseDLL(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  Node *prevNode = NULL;
  Node *currNode = head;
  while (currNode != NULL) {
    prevNode = currNode->previous;

    currNode->previous = currNode->next;
    currNode->next = prevNode;

    currNode = currNode->previous;
  }
  return prevNode->previous;
}

int getLengthOfDLL(Node *head) {
  int len = 0;
  Node *temp = head;
  while (temp) {
    len++;
    temp = temp->next;
  }
  return len;
}
