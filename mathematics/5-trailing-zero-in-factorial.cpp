#include <math.h>
#include <iostream>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;

  for (int i = 5; i <= n; i *= 5) ans += floor(n / i);

  cout << ans << endl;
}
