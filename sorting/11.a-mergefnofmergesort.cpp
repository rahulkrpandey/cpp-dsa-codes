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

int main() {
  int a[] = {1, 3, 5, 7, 2, 4, 10, 12};

  merge(a, 0, 3, 7);

  for (int i = 0; i < 8; i++) cout << a[i] << " ";

  return 0;
}
