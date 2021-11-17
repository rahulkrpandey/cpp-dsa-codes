#include <iostream>
using namespace std;

int main() {
  string s = "rahul";
  cout << s << ' ' << &s << endl;
  s[0] = 'p';
  cout << s << ' ' << &s << endl;
}
