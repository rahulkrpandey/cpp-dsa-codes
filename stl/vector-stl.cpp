#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> a(5, -1);
  for (auto it : a) cout << it << " ";

  cout << endl;

  vector<int> a1(3, vector<int>);
  for (auto i1 : a1) {
    cout << endl;
  }
}
