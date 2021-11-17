#include <iostream>
using namespace std;

class computation {
 public:
  int power(int x, int n);
};

int computation::power(int x, int n) {
  int res = 1;
  while (n > 0) {
    if (n & 1) res *= x;

    n /= 2;
    x *= x;
  }
  return res;
}

int main() {
  computation c;
  cout << c.power(2, 3) << endl;
  cout << c.power(2, 0) << endl;
  cout << c.power(3, 3) << endl;
  cout << c.power(10, 3) << endl;
  cout << c.power(4, 4) << endl;
  cout << c.power(50, 2) << endl;
}
