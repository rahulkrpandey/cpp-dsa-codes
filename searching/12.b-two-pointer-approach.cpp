#include <iostream>
using namespace std;

bool search(int a[], int size, int key) {
  for (int i = 0; i < size - 1; i++) {
    int l = i + 1, r = size - 1;
    while (l < r) {
      int sum = a[l] + a[r] + a[i];
      if (sum == key)
        return true;
      else if (sum > key)
        r--;
      else
        l++;
    }
  }
  return false;
}

int main() {
  int a[] = {2, 3, 4, 8, 9, 20, 40};

  cout << search(a, 7, 3) << endl;
}
