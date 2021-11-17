#include <iostream>
using namespace std;

int hcf(int a, int b) {
  if (b == 0)
    return a;

  else
    return hcf(b, a % b);
}

int lcm(int a, int b) { return (a * b) / hcf(a, b); }

int main() {
  cout << lcm(15, 7) << endl;
  cout << lcm(14, 12) << endl;
  cout << lcm(15, 20) << endl;
  cout << lcm(4, 6) << endl;
  cout << lcm(2, 5) << endl;
}
