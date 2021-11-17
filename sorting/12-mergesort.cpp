#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r) {
  int s1 = mid - l + 1, s2 = r - mid;
  int temp1[s1] = {0}, temp2[s2] = {0};

  for (int i = 0; i < s1; i++) temp1[i] = a[l + i];
  for (int i = 0; i < s2; i++) temp2[i] = a[mid + i + 1];

  int i = 0, j = 0, idx = 0;
  while (i < s1 && j < s2) {
    if (temp1[i] <= temp2[j]) {
      a[l + idx++] = temp1[i++];
    } else {
      a[l + idx++] = temp2[j++];
    }
  }

  while (i < s1) {
    a[l + idx++] = temp1[i++];
  }

  while (j < s2) {
    a[l + idx++] = temp2[j++];
  }
}

void mergesort(int a[], int l, int r) {
  if (l < r) {
    int mid = l + ((r - l) / 2);
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    merge(a, l, mid, r);
  }
}

int main() {
  int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  mergesort(a, 0, 9);

  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }

  return 0;
}
