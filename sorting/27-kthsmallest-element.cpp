#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int partition(int a[], int l, int r) {
  int pivot = a[r], i = l - 1, j = l;
  for (; j < r; j++) {
    if (a[j] < pivot) {
      swap(a, ++i, j);
    }
  }

  swap(a, ++i, r);
  return i;
}

int fucntion(int a[], int size, int k) {
  int l = 0, r = size - 1;

  while (l <= r) {
    int i = partition(a, l, r);

    if (i == k - 1)
      return a[i];
    else if (i > k - 1)
      r = i - 1;
    else
      l = i + 1;
  }

  return -1;
}

int main() {
  int a[] = {30, 20, 5, 10, 8};

  cout << fucntion(a, 5, 4) << endl;
}
