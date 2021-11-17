#include <iostream>
using namespace std;

int sqrt(int k) {
  int l = 1, r = k, result = -1;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (mid * mid == k)
      return mid;

    else if (mid * mid < k) {
      result = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }

  return result;
}

int main() {
  int k;
  cin >> k;
  cout << sqrt(k) << endl;
}
