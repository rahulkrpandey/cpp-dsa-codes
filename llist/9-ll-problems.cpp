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
  node* insertAtHead(int val);
  node* insertAtPos(int val, int pos);
  node* insertAtTail(int val);
  void display();
  int search(int key);
  int recSearch(node* head, int key);
  node* deleteHead();
  node* deleteTail();
  node* ninsertAtLl(int val);  // insert in sorted ll in such a manner that list
                               // is always sorted (my solution)
  node* insertAtLl(int val);   // insert in sorted ll in such a manner that list
                               // is always sorted (sir slightly better)

  void printMid();            // Always prints mid element, and if size is even
                              // print size/2 + 1th element
  void printKfromEnd(int k);  // print kth node form end
  node* reverseList();        // Iterative reverse
  node* reverseListRecursive1(node* head);              // recursive solution
  node* reverseListRecursive2(node* prev, node* head);  // recursive solution
  node* reverseKNodesGroup(int k);
  node* reverseKNodesGroupRecursive(node* head, int k);
  node* segregateEvenOdd();  // group even value and odd value separete together
                             // with previous order
  node* removeDuplicates();
  void destroy();
};

void list::display() {  // function to display linked list
  node* temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

node* list::insertAtHead(
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

node* list::insertAtTail(int val) {
  node* n = new node(val);
  if (head == NULL) return n;

  node* temp = head;
  while (temp->next != NULL) temp = temp->next;

  temp->next = n;
  return head;
}

node* list::insertAtPos(int val, int pos) {
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

node* list::ninsertAtLl(int val) {  // insert in a sorted ll in such a manner
                                    // that it is always sorded
  // Approach 1st, maintaining two pointers,
  node* n = new node(val);

  if (head == NULL) return n;

  node* prv = NULL;
  node* nxt = head;
  while (nxt != NULL && nxt->data <= val) {
    prv = nxt;
    nxt = nxt->next;
    // if (nxt == NULL) break;  -> this condition is needed if we write
    // condition like nxt -> data <= val && nxt != NULL
  }

  if (prv != NULL && nxt == NULL) {
    prv->next = n;
    return head;
  }

  n->next = nxt->next;
  nxt->next = n;
  int temp = n->data;
  n->data = nxt->data;
  nxt->data = temp;
  return head;
}

node* list::insertAtLl(
    int val) {  // slightly better solution insert in a sorted ll in such a
                // manner that it is always sorded

  node* n = new node(val);
  if (head == NULL) return n;
  if (head->data > val) {
    n->next = head;
    return n;
  }

  node* temp = head;
  while (temp->next != NULL && temp->next->data < val) temp = temp->next;

  n->next = temp->next;
  temp->next = n;
  return head;
}

void list::printMid() {
  // Naive solution is, do two travarsal
  // in first travarsal count number of nodes
  // then compare size, and do second travarsal of size/2 and print mid element
  // it requres two travarsal
  // it can be done in one travarsal also using slow and fast pointers
  /* ..........................................................................................
    my solution, it also run only for single travarsal
  if (head == NULL) return;
  node* temp = head;
  int size = 1;
  for (node* i = head; i != NULL;
       i = i->next, size++)
    if ((size % 2) == 0) temp = temp->next;

  cout << temp->data << endl;
  .............................................................................................*/

  // sir's approach slightly better based on slow and fast pointer

  if (head == NULL) return;
  node *slow = head, *fast = head;
  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
  }

  cout << slow->data << endl;
}

void list::printKfromEnd(int k) {
  // Naive solution is to find size of linked first
  // then traverse list second time and print n -k +1th node data
  // but it takes two travarsal
  // it can be done in single travarsal as well

  // Efficient approach ->
  /* my solution
  if (head == NULL) return;
  int size = 1, res = 0;
  node* temp = head;
  for (node* i = head; i != NULL; i = i->next, size++) {
    if (k > size) continue;
    res = temp->data;
    temp = temp->next;
  }

  if (size >= k) cout << res << endl;
  */
  // slight change
  if (head == NULL) return;
  int size = 1, res = 0;
  node* temp = head;
  for (node* i = head; i != NULL; i = i->next, size++) {
    if (k >= size) continue;  // change is done here
    temp = temp->next;
  }

  if (size >= k) cout << temp->data << endl;
}

node* list::reverseList() {
  // naive solution is to create auxilary array, copy all element of list in array in one travarsal\
  // then on the second traversal, copy back element of array in linked list in reverse order
  // but it requires two traversal and extra auxilary space
  if (head == NULL) return NULL;
  node *current = head, *prev = NULL;
  for (node* nxt = head->next; nxt != NULL; nxt = nxt->next) {
    current->next = prev;
    prev = current;
    current = nxt;
  }

  current->next = prev;
  return current;
}

node* list::reverseListRecursive1(node* Head) {
  // here we are reversing last n-1 nodes and then linking first node with list
  if (head == NULL) return NULL;
  if (Head->next == NULL) return Head;
  node* temp = Head->next;
  node* newHead = reverseListRecursive1(temp);
  temp->next = Head;
  Head->next = NULL;
  return newHead;
}

node* list::reverseListRecursive2(node* prev, node* Head) {
  // here we are reversing first n-1 node then linking last node to the list
  /* my solution
  if (Head == NULL) return NULL;
  if (Head->next == NULL) {
    Head->next = prev;
    return Head;
  }

  node* current = Head->next;
  Head->next = prev;
  prev = Head;
  return reverseListRecursive2(prev, current);
  */
  // slightly better
  if (Head == NULL) return prev;

  node* current = Head->next;
  Head->next = prev;
  return reverseListRecursive2(Head, current);
}

node* list::reverseKNodesGroup(int k) {
  if (head == NULL || head->next == NULL || k == 1) return head;

  node* dummy = new node(0);
  dummy->next = head;
  node *prev = dummy, *cur = head;
  while (cur != NULL && cur->next != NULL) {
    for (int i = 1; i < k; i++) {
      node* temp = prev->next;
      prev->next = cur->next;
      cur->next = cur->next->next;
      prev->next->next = temp;
      if (cur->next == NULL) break;
    }
    prev = cur;
    cur = prev->next;
  }

  head = dummy->next;
  delete dummy;
  return head;
}

node* list::reverseKNodesGroupRecursive(node* head, int k) {
  if (head == NULL || head->next == NULL) return head;
  node* prev = new node(0);
  prev->next = head;
  node* cur = head;

  for (int i = 1; i < k; i++) {
    node* temp = prev->next;
    prev->next = cur->next;
    cur->next = cur->next->next;
    prev->next->next = temp;
    if (cur->next == NULL) break;
  }

  cur->next = reverseKNodesGroupRecursive(cur->next, k);
  head = prev->next;
  delete prev;
  return head;
}

node* list::removeDuplicates() {
  if (head == NULL) return NULL;
  node* temp = head;
  while (temp->next != NULL) {
    if (temp->next->data == temp->data) {
      node* todelete = temp->next;
      temp->next = todelete->next;
      delete todelete;
      todelete = NULL;
    }

    else
      temp = temp->next;
  }
  return head;
}

node* list::segregateEvenOdd() {
  if (head == NULL || head->next == NULL) return head;

  node* dummy = new node(-1);
  dummy->next = head;
  node *prev = dummy, *nxt = dummy;
  while (nxt->next != NULL && nxt->next->data % 2 == 0) {
    nxt = nxt->next;
    prev = prev->next;
  }

  while (nxt->next != NULL) {
    if (nxt->next->data % 2 == 0) {
      node* temp = prev->next;
      prev->next = nxt->next;
      nxt->next = nxt->next->next;
      prev->next->next = temp;
      prev = prev->next;
    } else
      nxt = nxt->next;
  }

  head = dummy->next;
  delete dummy;
  dummy = NULL;
  return head;
}

int list::search(int key) {
  node* temp = head;
  for (int i = 1; temp != NULL; i++) {
    if (temp->data == key) return i;

    temp = temp->next;
  }

  return -1;
}

int list::recSearch(node* head, int key) {
  if (head == NULL) return -1;

  static int position = 1;
  if (head->data == key)
    return position;
  else {
    position++;
    return recSearch(head->next, key);
  }
}

node* list::deleteHead() {  // delete at the head position
  if (head == NULL) return NULL;

  node* temp = head;
  head = head->next;
  delete temp;
  temp = NULL;
  return head;
}

node* list::deleteTail() {
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

void list::destroy() {  // function to destroye linked list
  while (head != NULL) {
    node* temp = head;
    head = head->next;
    delete temp;
    temp = NULL;
  }
}

int main() {
  list l, m, n, o, p, q, r, s;

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
  l.head = l.insertAtHead(10);
  l.head = l.insertAtTail(20);
  l.head = l.insertAtTail(30);
  l.head = l.insertAtTail(40);
  m.head = m.insertAtHead(10);
  m.head = m.insertAtTail(25);
  n.head = n.insertAtHead(10);
  n.head = n.insertAtTail(20);

  l.display();
  l.head = l.insertAtLl(25);
  l.display();

  m.display();
  m.head = m.insertAtLl(5);
  m.display();

  n.display();
  n.head = n.insertAtLl(30);
  n.display();

  o.head = o.insertAtLl(10);
  o.display();

  cout << endl;
  l.printMid();
  m.printMid();
  n.printMid();
  o.printMid();

  cout << "printkfromend fn\n";
  l.printKfromEnd(2);
  l.printKfromEnd(3);
  m.printKfromEnd(1);
  n.printKfromEnd(3);
  o.printKfromEnd(1);
  o.printKfromEnd(4);

  cout << endl << "reversed list" << endl;
  l.head = l.reverseList();
  m.head = m.reverseList();
  n.head = n.reverseList();
  o.head = o.reverseList();
  l.display();
  m.display();
  n.display();
  o.display();
  cout << endl << "recursive reverse" << endl;
  l.head = l.reverseListRecursive1(l.head);
  m.head = m.reverseListRecursive1(m.head);
  n.head = n.reverseListRecursive1(n.head);
  o.head = o.reverseListRecursive1(o.head);
  l.display();
  m.display();
  n.display();
  o.display();

  cout << endl << "recursive reverse 2" << endl;
  l.head = l.reverseListRecursive2(NULL, l.head);
  m.head = m.reverseListRecursive2(NULL, m.head);
  n.head = n.reverseListRecursive2(NULL, n.head);
  o.head = o.reverseListRecursive2(NULL, o.head);
  l.display();
  m.display();
  n.display();
  o.display();

  cout << endl << "remove duplicate problems" << endl;
  p.head = p.insertAtHead(2);
  q.head = q.insertAtHead(2);
  r.head = r.insertAtHead(2);
  p.head = p.insertAtTail(2);
  p.head = p.insertAtTail(2);
  p.head = p.insertAtTail(3);
  p.head = p.insertAtTail(4);
  p.head = p.insertAtTail(4);
  p.head = p.insertAtTail(5);
  q.head = q.insertAtTail(5);
  q.head = q.insertAtTail(5);
  q.head = q.insertAtTail(5);
  p.display();
  q.display();
  r.display();
  p.head = p.removeDuplicates();
  q.head = q.removeDuplicates();
  r.head = r.removeDuplicates();
  p.display();
  q.display();
  r.display();
  cout << endl << "reverse k groups\n";
  l.head = l.reverseKNodesGroup(2);
  l.display();
  m.head = m.reverseKNodesGroup(2);
  m.display();
  n.head = n.reverseKNodesGroup(4);
  n.display();
  n.head = n.reverseKNodesGroup(3);
  n.display();

  cout << endl << "reverse k groups\n";
  s.head = s.insertAtHead(7);
  s.head = s.insertAtHead(6);
  s.head = s.insertAtHead(5);
  s.head = s.insertAtHead(4);
  s.head = s.insertAtHead(10);
  s.head = s.insertAtHead(2);
  s.head = s.insertAtHead(1);
  s.display();
  s.head = s.reverseKNodesGroupRecursive(s.head, 3);
  s.display();
  s.segregateEvenOdd();
  cout << "after segregation\n";
  s.display();

  l.destroy();
  m.destroy();
  n.destroy();
  p.destroy();
  q.destroy();
  r.destroy();
  s.destroy();
}
