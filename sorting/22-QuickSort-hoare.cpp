#include <iostream>
using namespace std;

void swap(int* a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int partition(int* a, int l, int r) {
  int pivot = a[l], i = l - 1, j = r + 1;

  while (true) {
    do {
      i++;
    } while (a[i] < pivot);
    do {
      j--;
    } while (a[j] > pivot);

    if (i >= j)
      return j;
    else
      swap(a, i, j);
  }

  return j;
}

void qSort(int* a, int l, int r) {
  if (l < r) {
    int idx = partition(a, l, r);
    qSort(a, l, idx);
    qSort(a, idx + 1, r);
  }
}

int main() {
  int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  qSort(a, 0, 9);

  for (int i = 0; i < 10; i++) cout << a[i] << " ";

  cout << endl;
}
