#include <iostream>
#include <vector>
using namespace std;

class prime {
 public:
  void printPrime(int n);
};

void prime::printPrime(int n) {
  if (n < 2) return;

  vector<bool> isPrime(n + 1, true);

  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      cout << i << " ";
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }
  cout << endl;
}

int main() {
  prime p;
  p.printPrime(1);
  p.printPrime(2);
  p.printPrime(5);
  p.printPrime(10);
  p.printPrime(40);
  p.printPrime(100);
}
