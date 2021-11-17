#include <iostream>
using namespace std;

bool isPrime(int n) {
  if (n == 1) return false;
  if (n == 2 || n == 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;

  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;

  return true;
}

int main() {
  cout << isPrime(3) << endl;
  cout << isPrime(2) << endl;
  cout << isPrime(1) << endl;
  cout << isPrime(17) << endl;
  cout << isPrime(14) << endl;
  cout << isPrime(1031) << endl;
}
