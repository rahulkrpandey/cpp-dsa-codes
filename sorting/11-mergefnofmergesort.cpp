// Failed in merge sort.....segmentation fault
#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int r) {
  int i = 0, j = mid + 1, idx = 0;
  int temp[r - l + 1] = {0};
  while (i <= mid && j <= r) {
    if (a[i] <= a[j])
      temp[idx++] = a[i++];
    else
      temp[idx++] = a[j++];
  }

  while (i <= mid) {
    temp[idx++] = a[i++];
  }

  while (j <= r) {
    temp[idx++] = a[j++];
  }

  for (int k = l; k <= r; k++) {
    a[k] = *(temp + k);
  }
}

int main() {
  int a[]{1, 3, 5, 7, 2, 3, 6, 8};

  merge(a, 0, 3, 7);

  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
}
