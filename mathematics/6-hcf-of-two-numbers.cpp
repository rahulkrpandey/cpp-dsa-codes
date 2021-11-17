#include <iostream>
using namespace std;

int hcf(int a, int b) {
  if (b == 0)
    return a;

  else
    return hcf(b, a % b);
}

int main() {
  cout << hcf(12, 15) << endl;
  cout << hcf(12, 17) << endl;
  cout << hcf(2, 5) << endl;
  cout << hcf(16, 32) << endl;
  cout << hcf(6, 8) << endl;
  cout << hcf(50, 125) << endl;
}
