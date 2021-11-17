#include <math.h>
#include <iostream>
using namespace std;

int main() {
  int n, m = 0;
  cin >> n;
  while (n > 0) {
    n /= 10;
    m++;
  }
  cout << m << endl;
}
