#include <iostream>
using namespace std;

void swap(int* a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int pivotIdx(int* a, int l, int r) {
  int pivot = a[r], i = l - 1, j = l;

  while (j < r) {
    if (a[j] > pivot)
      j++;
    else
      swap(a, ++i, j++);
  }

  swap(a, ++i, r);

  return i;
}

void qSort(int* a, int l, int r) {
  if (l < r) {
    int idx = pivotIdx(a, l, r);

    qSort(a, l, idx - 1);
    qSort(a, idx + 1, r);
  }
}

int main() {
  int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  qSort(a, 0, 9);

  for (int i = 0; i < 10; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
}
