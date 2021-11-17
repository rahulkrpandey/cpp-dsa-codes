#include <iostream>
#include <stack>
using namespace std;

void function(int a[], int size) {
  stack<int> s;

  for (int i = 0; i < size; i++) {
    while (!s.empty() && s.top() >= a[i]) {
      s.pop();
    }

    if (s.empty())
      cout << -1 << " ";

    else
      cout << s.top() << " ";

    s.push(a[i]);
  }
}

int main() {
  int a[] = {4, 10, 5, 8, 20, 15, 3, 12};

  function(a, 8);
}
