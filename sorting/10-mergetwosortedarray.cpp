#include <iostream>
using namespace std;

void merge(int a[], int s1, int b[], int s2) {
  int i = 0, j = 0;

  while (i < s1 && j < s2) {
    if (a[i] <= b[j]) {
      cout << a[i++] << " ";
    } else
      cout << b[j++] << " ";
  }

  while (i < s1) {
    cout << a[i++] << " ";
  }

  while (j < s2) {
    cout << b[j++] << " ";
  }
}

int main() {
  int a[] = {2, 4, 5, 6, 8};

  int b[] = {1, 3, 5, 7};

  merge(a, 5, b, 4);
  return 0;
}
