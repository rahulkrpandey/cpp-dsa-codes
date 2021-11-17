#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int sort(int a[], int size, int b, int c) {
  int l = 0, mid = 0, r = size - 1;

  while (mid <= r) {
    if (a[mid] < b) {
      swap(a, l, mid);
      l++;
      mid++;
    } else if (a[mid] >= b && a[mid] <= c)
      mid++;
    else {
      swap(a, mid, r);
      r--;
    }
  }

  return 0;
}

int main() {
  int a[] = {0, 1, 4, 3, 6, 7, 5, 4, 2, 1, 4, 8, 9, 0};

  sort(a, 14, 4, 7);

  for (int i = 0; i < 14; i++) cout << a[i] << " ";

  cout << endl;
}
