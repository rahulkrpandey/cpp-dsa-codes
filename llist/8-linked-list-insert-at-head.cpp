#include <iostream>
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
 public:
  node* head;
  list() { head = NULL; }
};

void display(node* head) {  // function to display linked list
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }

  cout << endl;
}

node* insertAtHead(node* head,
                   int val) {  // function to insert at head at linked list
  node* n = new node(val);
  if (head == NULL) {
    return n;
  }

  node* temp = new node(val);
  temp->next = head;
  head = temp;
  return head;
}

node* insertAtTail(node* head, int val) {
  node* n = new node(val);
  if (head == NULL) return n;

  node* temp = head;
  while (temp->next != NULL) temp = temp->next;

  temp->next = n;
  return head;
}

node* insertAtPos(node* head, int val, int pos) {
  if (pos < 1) return head;
  node* n = new node(val);
  if (pos == 1) {
    n->next = head;
    return n;
  }

  node* temp = head;
  for (int i = 1; i <= pos - 2 && temp != NULL; i++) temp = temp->next;

  if (temp == NULL) {
    delete n;
    return head;
  }

  n->next = temp->next;
  temp->next = n;
  return head;
}

int search(node* head, int key) {
  node* temp = head;
  for (int i = 1; temp != NULL; i++) {
    if (temp->data == key) return i;

    temp = temp->next;
  }

  return -1;
}

int recSearch(node* head, int key) {
  if (head == NULL) return -1;

  static int position = 1;
  if (head->data == key)
    return position;
  else {
    position++;
    return recSearch(head->next, key);
  }
}

node* deleteHead(node* head) {  // delete at the head position
  if (head == NULL) return NULL;

  node* temp = head;
  head = head->next;
  delete temp;
  temp = NULL;
  return head;
}

node* deleteTail(node* head) {
  if (head == NULL) return NULL;
  if (head->next == NULL) {
    delete head;
    return NULL;
  }

  node* temp = head;
  while (temp->next->next != NULL) temp = temp->next;

  delete temp->next;
  temp->next = NULL;
  return head;
}

void destroy(node*& head) {  // function to destroye linked list
  node* temp = head;
  while (head != NULL) {
    head = head->next;
    delete temp;
    temp = NULL;
  }
}

int main() {
  list l;
  /*
  l.head = new node(10);
  l.head = insertAtHead(l.head, 20);
  l.head = insertAtTail(l.head, 30);
  display(l.head);
  l.head = deleteHead(l.head);
  display(l.head);
  l.head = deleteTail(l.head);
  display(l.head);
  l.head = insertAtPos(l.head, 5, 1);
  l.head = insertAtPos(l.head, 15, 3);
  l.head = insertAtPos(l.head, 14, 3);
  l.head = insertAtPos(l.head, 38, 8);
  display(l.head);
  cout << search(l.head, 5);
  cout << search(l.head, 14);
  cout << search(l.head, 15);
  cout << search(l.head, 30) << endl;
  cout << recSearch(l.head, 55) << endl;
  */

  l.head = insertAtHead(l.head, )

      destroy(l.head);
}
