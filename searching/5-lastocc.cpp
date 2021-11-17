#include <iostream>
using namespace std;

int search(int* a, int size, int key) {
  int l = 0, r = size - 1, result = -1;

  while (l <= r) {
    int mid = (l + r) / 2;
    if (a[mid] == key) {
      result = mid;
      l = mid + 1;
    } else if (a[mid] > key) {
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return result;
}

int main() {
  int a[] = {
      1, 2, 2, 3, 3, 3, 4, 4,
  };

  cout << search(a, 8, 1) << endl;
  return 0;
}
