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
      a[idx++] = temp1[i++];
    } else
      a[idx++] = temp2[j++];
  }

  while (i < n) {
    a[idx++] = temp1[i++];
  }

  while (j < m) {
    a[idx++] = temp2[j++];
  }
}

int main() {
  int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  mergefn(a, 0, 4, 9);
  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
}
