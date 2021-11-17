#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int sort(int a[], int size) {
  int l = 0, mid = 0, r = size - 1;

  while (mid <= r) {
    if (a[mid] == 0) {
      swap(a, l, mid);
      l++;
      mid++;
    } else if (a[mid] == 1)
      mid++;
    else {
      swap(a, mid, r);
      r--;
    }
  }

  return 0;
}

int main() {
  int a[] = {0, 1, 2, 1, 0, 0, 1, 2, 2, 1, 0, 1};

  sort(a, 12);

  for (int i = 0; i < 12; i++) cout << a[i] << " ";

  cout << endl;
}
