#include <iostream>
using namespace std;

void printPF(int n) {
  if (n <= 1) {
    cout << "not prime factor exist\n";
    return;
  }

  while (n % 2 == 0) {
    cout << 2 << " ";
    n /= 2;
  }

  while (n % 3 == 0) {
    cout << 3 << " ";
    n /= 3;
  }

  for (int i = 5; i * i <= n; i++) {
    while (n % i == 0) {
      cout << i << " ";
      n /= i;
    }

    while (n % (i + 2) == 0) {
      cout << (i + 2) << " ";
      n /= (i + 2);
    }
  }

  if (n > 3) cout << n << " ";
  cout << endl;
}

int main() {
  printPF(64);
  printPF(315);
  printPF(100);
  printPF(12);
  printPF(25);
  printPF(17);
}
