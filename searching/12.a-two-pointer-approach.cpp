#include <iostream>
using namespace std;

bool search(int a[], int size, int key) {
  int l = 0, r = size - 1;
  while (l < r) {
    int sum = a[l] + a[r];
    if (sum == key)
      return true;
    else if (sum > key)
      r--;
    else
      l++;
  }

  return false;
}

int main() {
  int a[] = {2, 4, 8, 9, 11, 12, 20, 30};

  cout << search(a, 8, 17) << endl;
  cout << search(a, 8, 18) << endl;
  cout << search(a, 8, 10) << endl;
  cout << search(a, 8, 121) << endl;
}
