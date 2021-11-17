#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

int distribute(int a[], int size, int m) {
  if (m > size) return -1;
  sort(a, a + size);
  int ans = a[m - 1] - a[0];

  for (int i = 1; i + m - 1 < size; i++) ans = min(ans, a[i + m - 1] - a[i]);

  return ans;
}

int main() {
  int a[] = {3, 4, 9, 56, 7, 9, 12};

  cout << distribute(a, 7, 5) << endl;
}
