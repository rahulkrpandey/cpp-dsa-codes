#include <bits/stdc++.h>
using namespace std;

int isFeasible(int* a, int size, int k, int pages) {
  int sum = 0, count = 0, i = 0;
  while (i < size) {
    sum += a[i];
    if (sum > pages) {
      sum = a[i];
      count++;
    }
    i++;
  }

  return (count < k);
}

int find(int* a, int size, int k) {
  int r = 0, l = INT_MIN, result = 0;

  for (int i = 0; i < size; i++) {
    r += a[i];
    l = max(l, a[i]);
  }

  while (l <= r) {
    int mid = (l + r) / 2;
    if (isFeasible(a, size, k, mid)) {
      result = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return result;
}

int main() {
  int a[] = {10, 20, 10, 30};
  cout << find(a, 4, 2) << endl;
}
