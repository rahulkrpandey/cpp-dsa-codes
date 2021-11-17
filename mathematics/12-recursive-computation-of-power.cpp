#include <iostream>
using namespace std;

class computation {
 public:
  int power(int x, int n);
};

int computation::power(int x, int n) {
  if (n == 0) return 1;

  int temp = computation::power(x, n / 2);

  if (n % 2 == 0)
    return temp * temp;

  else
    return temp * temp * x;
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
