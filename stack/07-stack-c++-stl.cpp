#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<int> sk;
  sk.push(1);
  sk.push(2);
  sk.push(3);
  sk.push(4);
  cout << sk.top() << endl;
  sk.pop();
  cout << sk.top() << endl;

  while (!sk.empty()) {
    cout << sk.top() << endl;
    sk.pop();
  }

  cout << sk.size()<< endl;
}
