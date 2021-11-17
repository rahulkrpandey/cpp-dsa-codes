#include <iostream>
using namespace std;

struct node {
  int data;
  struct node* next;
};

struct node* createNode(int data) {
  struct node* temp = new node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void destroyList(struct node* head) {
  struct node* temp = head;
  while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
  }
}

void display(struct node* head) {
  // struct node* temp = head;
  while (head != NULL) {
    cout << head->data << endl;
    head = head->next;
  }
}

void recursiveDisplay(struct node* head) {
  if (head == NULL) {
    cout << endl;
    return;
  }

  cout << head->data << " ";
  recursiveDisplay(head->next);
}

int main() {
  struct node* head;
  head = createNode(20);
  head->next = createNode(30);
  head->next->next = createNode(40);
  head->next->next->next = createNode(50);
  recursiveDisplay(head);
  destroyList(head);
}
