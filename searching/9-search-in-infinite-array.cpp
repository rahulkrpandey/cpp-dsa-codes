#include <iostream>
using namespace std;

int binarysearch(int* a, int l, int r, int key) {
  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == key)
      return mid;
    else if (a[mid] < key)
      l = mid + 1;
    else
      r = mid - 1;
  }

  return -1;
}

int search(int a[], int key) {
  if (a[0] == key) return 0;
  int r = 1, l = 1;
  while (a[r] < key) {
    r *= 2;
  }

  if (a[r] == key) return r;
  return binarysearch(a, r / 2 + 1, r - 1, key);
}

int main() {
  int a[] = {1, 10, 15, 20, 40, 50, 90, 100, 120, 500};

  cout << search(a, 500) << endl;
}
