#include <iostream>
using namespace std;

int search(int* a, int size) {
  int l = 0, r = size - 1;
  while (l <= r) {
    int mid = (l + r) / 2;

    if ((mid == 0 || a[mid - 1] <= a[mid]) &&
        (mid == size - 1 || a[mid + 1] <= a[mid]))
      return a[mid];

    if (mid > 0 && a[mid - 1] >= a[mid]) {
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return -1;
}

int main() {
  int a[] = {5, 10, 50, 40, 90, 80, 70};

  cout << search(a, 7) << endl;
}
