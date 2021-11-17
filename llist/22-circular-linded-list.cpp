#include <iostream>
#include <vector>
using namespace std;

class node {
 public:
  int data;
  node* next;
  node(int val) {
    data = val;
    next = NULL;
  }
};

class list {
  node* head;

 public:
  list() { head = NULL; }

  void ninsertAtHead(int data);  // thera(n) time complexity (noob solution)
  void insertAtHead(int data);   // thera(1) time complexity (pro solution)
  void insertAtTail(int data);   // thera(1) time complexity (pro solution)
  void display();
  void ndeleteHead();      // noob solution in theta(n) time
  void deleteHead();       // pro solution in theta(1) time
  void ndeletekth(int k);  // my solution
  void deletekth(int k);   // sir solution
  void destroy();
};

void list::ninsertAtHead(
    int data) {  // thera(n) time complexity (noob solution)
  node* n = new node(data);

  if (head == NULL) {
    head = n;
    head->next = head;
    return;
  }

  node* temp = head;
  while (temp->next != head) temp = temp->next;

  n->next = head;
  temp->next = n;
  head = n;
}

void list::insertAtHead(int data) {
  node* n = new node(data);

  if (head == NULL) {
    head = n;
    head->next = head;
    return;
  }

  n->next = head->next;
  head->next = n;

  int temp = head->data;
  head->data = n->data;
  n->data = temp;
}

void list::insertAtTail(int data) {  // pro solution theta(1)
  node* n = new node(data);

  if (head == NULL) {
    head = n;
    head->next = head;
    return;
  }

  n->next = head->next;
  head->next = n;

  int temp = head->data;
  head->data = n->data;
  n->data = temp;
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

void list::ndeleteHead() {  // noob solution in theta(n) time complexity
  if (head == NULL) return;
  if (head->next == head) {
    delete head;
    head = NULL;
    return;
  }

  node* todelete = head;
  node* temp = head;
  while (temp->next != head) temp = temp->next;

  head = head->next;
  temp->next = head;
  delete todelete;
  todelete = NULL;
}

void list::deleteHead() {  // pro solution in theta(1) time
  if (head == NULL) return;
  if (head->next == head) {
    delete head;
    head = NULL;
    return;
  }

  node* todelete = head->next;
  head->data = head->next->data;
  head->next = todelete->next;
  delete todelete;
  todelete = NULL;
}

void list::ndeletekth(int k) {  // my solution
  if (head == NULL) return;
  int size = 0;
  node* temp = head;
  do {
    size++;
    temp = temp->next;
  } while (temp != head);

  if (k > size) return;

  if (k == 1) {
    deleteHead();
    return;
  }

  if (k == 2) {
    node* todelete = head->next;
    head->next = todelete->next;
    delete todelete;
    todelete = NULL;
    return;
  }

  int count = 1;
  temp = head;
  do {
    count++;
    temp = temp->next;
  } while (count <= k - 2 && temp != head);

  node* todelete = temp->next;
  temp->next = todelete->next;
  delete todelete;
  todelete = NULL;
}

void list::deletekth(int k) {  // sir solution
  if (head == NULL) return;
  int size = 0;
  node* temp = head;
  do {
    size++;
    temp = temp->next;
  } while (temp != head);

  if (k > size) return;

  if (k == 1) {
    deleteHead();
    return;
  }

  temp = head;
  for (int i = 0; i < k - 2; i++) temp = temp->next;

  node* todelete = temp->next;
  temp->next = todelete->next;
  delete todelete;
  todelete = NULL;
}

void list::destroy() {
  if (head == NULL) return;

  node* temp = head->next;
  head->next = NULL;
  head = temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
  }
}

int main() {
  list l, m, n;
  l.insertAtHead(30);
  l.insertAtHead(20);
  l.insertAtHead(10);
  l.insertAtHead(0);
  l.display();
  l.deleteHead();
  l.display();
  l.destroy();

  m.insertAtHead(100);
  m.deleteHead();
  m.display();
  m.insertAtTail(10);
  m.display();
  m.destroy();

  n.insertAtTail(1);
  n.insertAtTail(2);
  n.insertAtTail(3);
  n.insertAtTail(4);
  n.insertAtTail(5);
  n.insertAtTail(6);
  n.deletekth(1);
  n.display();
  n.deletekth(5);
  n.display();
  n.deletekth(3);
  n.display();
  n.deletekth(2);
  n.display();
  n.deletekth(3);
  n.display();
  n.destroy();
}
