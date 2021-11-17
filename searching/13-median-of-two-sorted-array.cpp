#include <bits/stdc++.h>
using namespace std;

double median(int* p1, int n, int* p2, int m) {
  int *a1 = NULL, *a2 = NULL;
  if (n <= m) {
    a1 = p1;
    a2 = p2;
  } else {
    a1 = p2;
    a2 = p1;
  }

  int l = 0, r = n;
  while (l <= r) {
    int i1 = (l + r) / 2;
    int i2 = (m + n + 1) / 2 - i1;

    int min1 = (i1 == n) ? INT_MAX : a1[i1];
    int min2 = (i2 == m) ? INT_MAX : a2[i2];
    int max1 = (i1 == 0) ? INT_MIN : a1[i1 - 1];
    int max2 = (i2 == 0) ? INT_MIN : a2[i2 - 1];

    if (max1 <= min2 && max2 <= min1) {
      if ((m + n) % 2 == 0) {
        return ((double)(max(max1, max2) + min(min1, min2)) / 2);
      } else {
        return (double)max(max1, max2);
      }
    } else if (max1 > min2) {
      r = i1 - 1;
    } else {
      l = i1 + 1;
    }
  }

  return -1;
}

int main() {
  int a1[] = {10, 20, 30, 40, 50};
  int a2[] = {5, 15, 25, 35, 45, 55};

  cout << median(a1, 5, a2, 5) << endl;
}
