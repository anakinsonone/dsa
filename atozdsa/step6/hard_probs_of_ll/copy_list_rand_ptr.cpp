#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

void insertCopyInBetween(Node *head) {
  Node *temp = head;
  while (temp) {
    Node *nextNode = temp->next;

    Node *copy = new Node(temp->val);

    copy->next = nextNode;
    temp->next = copy;

    temp = nextNode;
  }
}

void connectRandomPointers(Node *head) {
  Node *temp = head;
  while (temp) {
    if (temp->random) {
      temp->next->random = temp->random->next;
    } else {
      temp->next->random = nullptr;
    }
    temp = temp->next->next;
  }
}

Node *getCopiedList(Node *head) {
  Node *temp = head;
  Node *d = new Node(-1);
  Node *res = d;

  while (temp) {
    res->next = temp->next;
    res = res->next;

    temp->next = res->next;
    temp = temp->next;
  }

  return d->next;
}

Node *cloneList(Node *head) {
  if (!head)
    return nullptr;

  insertCopyInBetween(head);

  connectRandomPointers(head);

  return getCopiedList(head);
}

int main() {
  Node *head = new Node(7);
  head->next = new Node(13);
  head->next->next = new Node(11);
  head->next->next->next = new Node(10);
  head->next->next->next->next = new Node(1);
  head->next->random = head;
  head->next->next->random = head->next->next->next->next;
  head->next->next->next->random = head->next->next;
  head->next->next->next->next->random = head;

  Node *newHead = cloneList(head);
  Node *temp = newHead;

  while (temp) {
    if (temp->random) {
      cout << temp->val << " ~> " << temp->random->val << '\n';
    } else {
      cout << temp->val << " ~>\n";
    }
    temp = temp->next;
  }

  return 0;
}
