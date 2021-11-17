#include <iostream>
using namespace std;

int search(int* a, int size, int key) {
  int l = 0, r = size - 1;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (a[mid] == key) return mid;

    if (a[l] < a[mid]) {
      if (key >= a[l] && key < a[mid])
        r = mid - 1;
      else
        l = mid + 1;
    } else {
      if (key > a[mid] && key <= a[r])
        l = mid + 1;
      else
        r = mid - 1;
    }
  }

  return -1;
}

int main() {
  int a[] = {50, 60, 70, 80, 10, 20};

  cout << search(a, 6, 60) << endl;
  cout << search(a, 6, 10) << endl;
  cout << search(a, 6, 50) << endl;
  cout << search(a, 6, 20) << endl;
  cout << search(a, 6, 25) << endl;
}
