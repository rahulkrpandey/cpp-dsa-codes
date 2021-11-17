#include <iostream>
using namespace std;

// print in increasing order
int printDivisor(int n) {
  int i = 1;

  for (; i * i < n; i++) {
    if (n % i == 0) cout << i << " ";
  }

  for (; i >= 1; i--) {
    if (n % i == 0) cout << n / i << " ";
  }

  cout << endl;
  return 0;
}

int main() {
  printDivisor(12);
  printDivisor(16);
  printDivisor(25);
  printDivisor(17);
  printDivisor(2);
}
