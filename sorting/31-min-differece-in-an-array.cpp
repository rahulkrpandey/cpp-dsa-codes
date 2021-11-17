#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

int minDifference(int a[], int size) {
  sort(a, a + size);
  int ans = INT_MAX;

  for (int i = 0; i < size - 1; i++) {
    ans = min(ans, a[i + 1] - a[i]);
  }

  return ans;
}

int main() {
  int a[] = {10, 8, 1, 4};
  cout << minDifference(a, 4) << endl;
}
