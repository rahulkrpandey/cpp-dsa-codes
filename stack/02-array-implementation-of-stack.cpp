#include <iostream>
#include <limits.h>
using namespace std;

class stack {
  public:
  int* arr;
  int capacity, top;
  stack(int cap) {
    arr=new int[cap];
    capacity=cap; 
    top=-1;
  }
};

int push(stack& st, int data) {
  if (st.top == st.capacity-1) {
    cout << "overflow\n" << endl;
    return INT_MAX;
  }

  st.top++;
  return st.arr[st.top]=data;
}

int pop(stack&st) {
  if (st.top == -1) {
    cout << "underflow\n";
    return INT_MAX;
  }
  st.top--;
  return st.arr[st.top+1];
}

int peek(stack& st) {
  if (st.top  == -1) {
    cout << st.top << endl;
    return INT_MAX;
  }
  return st.arr[st.top];
}

bool isEmpyt(stack st) {
  return st.top == -1;
}

int size(stack st) {
  return st.top+1;
}

void destroy(stack& st) {
  delete st.arr;
  st.arr=NULL;
  st.top=-1; st.capacity=0;
}

int main() {
  stack st(20);
  push(st, 7);
  push(st, 8);
  push(st, 9);
  cout << peek(st) << endl;

  pop(st);
  cout << peek(st) << endl;
  while (!isEmpyt(st)) {
    cout << peek(st) << endl;
    pop(st);
  }

  pop(st);

  destroy(st);
}
