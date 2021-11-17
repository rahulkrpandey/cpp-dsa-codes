#include <limits.h>
#include <array>
#include <iostream>
using namespace std;

int main() {
  array<int, 10> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  //  for (int i = 0; i < a.size(); i++) cout << a[i] << endl;

  //  for (auto it : a) cout << it << endl;

  for (auto it = a.begin(); it < a.end(); it++) {
    cout << *it << endl;
  }
  for (auto it = a.rbegin(); it < a.rend(); it++) {
    cout << *it << endl;
  }

  cout << a.at(4) << endl;
  cout << a.front() << endl;
  cout << a.back() << endl;
}
