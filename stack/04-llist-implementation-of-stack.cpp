#include<iostream>
#include<limits.h>

using namespace std;

class node {
  public:
  int data;
  node* next;
  node(int val) {
    data=val;
    next=NULL;
  }
};

class stack {
  public:
  node* head;
  int top;
  stack() {
    top=-1;
    head=NULL;
  }

  int push(int val);
  int pop();
  int peek();
  int size();
  bool isEmpty();
  void destroy();
};

int stack::push(int val) {
  node* n=new node(val);
  if (head==NULL) {
    head=n;
    top++;
    return val;
  }

  n->next=head;
  head=n;
  top++;
  return val;
}

int stack::pop() {
  if (top==-1) {
    cout << "underflow\n";
    return INT_MAX;
  }

  node* todelete=head;
  int val=head->data;
  head=head->next;
  delete todelete;
  top--;
  todelete=NULL;
  return val;
}

int stack::peek() {
  if (top==-1) {
    cout << "empty\n";
    return INT_MAX;
  }

  return head->data;
}

int stack::size() {
  return top+1;
}

bool stack::isEmpty() {
  return top==-1;
}

void stack::destroy() {
  while (head!=NULL) {
    node* temp=head;
    head=head->next;
    delete temp;
    temp=NULL;
  }
}

int main() {
  stack sk;
  sk.push(1);
  sk.push(2);
  sk.push(3);
  sk.push(4);
  sk.push(5);
  sk.push(6);
  cout << sk.peek() << endl;
  cout << "poping = " << sk.pop() << endl;
  cout << "after poping = " << sk.peek() << endl;
  while (!sk.isEmpty()) {
    cout << sk.peek() << endl;
    sk.pop();
  }
  
  sk.destroy();
  sk.pop();
  sk.peek();
}
