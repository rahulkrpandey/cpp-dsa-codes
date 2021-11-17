#include <iostream>
using namespace std;

int mergeandcount(int* a, int l, int mid,
                  int r) {  // inversion => if i < j in array and a[i] > a[j] ,
                            // inversion is min "0" if array is
  int i = 0, j = 0, count = 0, idx = 0, n = mid - l + 1, m = r - mid;
  int t1[n] = {0}, t2[m] = {0};

  for (int i = 0; i < n; i++) t1[i] = a[l + i];
  for (int i = 0; i < m; i++) t2[i] = a[mid + 1 + i];

  while (i < n && j < m) {
    if (t2[j] < t1[i]) {
      a[l + idx++] = t2[j++];
      count += (n - i);
    } else {
      a[l + idx++] = t1[i++];
    }
  }

  while (i < n) {
    a[l + idx++] = t1[i++];
  }

  while (j < m) {
    a[l + idx++] = t2[j++];
  }

  return count;
}

int Count(int* a, int l, int r) {
  int count = 0;
  if (l < r) {
    int mid = l + (r - l) / 2;
    count += Count(a, l, mid);
    count += Count(a, mid + 1, r);
    count += mergeandcount(a, l, mid, r);
  }

  return count;
}

int main() {
  int a[] = {6, 5, 4, 3, 2, 1};
  cout << Count(a, 0, 5) << endl;
}
