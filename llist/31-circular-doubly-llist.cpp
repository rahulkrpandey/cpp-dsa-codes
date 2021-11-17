#include <iostream>
using namespace std;

class node {
 public:
  int data;
  node* next;
  node* prev;
  node(int val) {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

class list {
  node* head;

 public:
  list() { head = NULL; }
  void insertAtHead(int val);
  void display();
  void destroy();
};

void list::insertAtHead(int val) {
  node* n = new node(val);
  if (head == NULL) {
    n->next = n;
    n->prev = n;
    head = n;
    return;
  }

  n->next = head;
  n->prev = head->prev;
  head->prev->next = n;
  head->prev = n;
  head = n;
}

void list::display() {
  if (head == NULL) return;
  node* temp = head;
  do {
    cout << temp->data << " ";
    temp = temp->next;
  } while (temp != head);
  cout << endl;
}

void list::destroy() {
  if (head == NULL) return;
  head->prev->next = NULL;
  head->prev = NULL;
  while (head != NULL) {
    node* todelete = head;
    head = head->next;
    delete todelete;
    todelete = NULL;
  }
}

int main() {
  list l;
  l.insertAtHead(4);
  l.insertAtHead(2);
  l.insertAtHead(3);
  l.insertAtHead(1);
  l.display();
  l.destroy();
}
