#include <iostream>
using namespace std;

void mergefn(int* a, int l, int mid, int r) {
  int n = mid - l + 1, m = r - mid;
  int temp1[n] = {0}, temp2[m] = {0};
  for (int i = 0; i < n; i++) temp1[i] = a[l + i];
  for (int i = 0; i < m; i++) temp2[i] = a[mid + 1 + i];

  int i = 0, j = 0, idx = 0;
  while (i < n && j < m) {
    if (temp1[i] <= temp2[j]) {
      a[l + idx++] = temp1[i++];
    } else
      a[l + idx++] = temp2[j++];
  }

  while (i < n) {
    a[l + idx++] = temp1[i++];
  }

  while (j < m) {
    a[l + idx++] = temp2[j++];
  }
}

void mergesort(int* a, int l, int r) {
  if (l < r) {
    int mid = l + ((r - l) / 2);
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    mergefn(a, l, mid, r);
  }
}

int main() {
  int a[] = {10, 9, 8, 7, 6};
  mergesort(a, 0, 4);
  for (int i = 0; i < 5; i++) cout << a[i] << " ";

  cout << endl;
}
