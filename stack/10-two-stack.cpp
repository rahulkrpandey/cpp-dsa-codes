#include<iostream>
#include<limits.h>
using namespace std;

class twoStack {
  int* arr;
  int tp1, tp2, capacity;
  public:
  twoStack(int cap) {
    capacity=cap;
    arr = new int[capacity];
    tp1 = -1;
    tp2 = capacity;
  }

  int push1(int val) {
    if (tp1 == tp2-1) return INT_MAX;
    arr[++tp1]=val;
    return arr[tp1];
  }

  int push2(int val) {
    if (tp2 == tp1+1) return INT_MAX;
    arr[--tp2] = val;
    return arr[tp2];
  }

  int pop1() {
    if (tp1==-1) return INT_MAX;
    tp1--;
    return arr[tp1+1];
  }

  int pop2() {
    if (tp2==capacity) return INT_MAX;
    tp2++;
    return arr[tp2-1];
  }

  int top1() {
    if (tp1==-1) return INT_MAX;
    return arr[tp1];
  }

  int top2() {
    if (tp2==capacity) return INT_MAX;
    return arr[tp2];
  }

  bool empty1() {
    return (tp1 == -1);
  }

  bool empty2() {
    return (tp2 == capacity);
  }
};

int main() {
  twoStack tw(10);
  tw.push1(1);
  tw.push1(2);
  tw.push1(3);
  tw.push1(4);
  tw.push2(5);
  tw.push2(6);
  tw.push2(7);
  tw.push2(8);

  while (!tw.empty1()) {
    cout << tw.top1() << endl;
    tw.pop1();
  }

  while (!tw.empty2()) {
    cout << tw.top2() << endl;
    tw.pop2();
  }
}
