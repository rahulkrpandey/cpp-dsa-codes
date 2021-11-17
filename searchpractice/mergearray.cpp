#include <iostream>
using namespace std;

void merge(int* a, int s1, int* b, int s2) {
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
  int a[] = {1, 3, 6, 7, 10};

  int b[] = {2, 4, 6, 8, 10};

  merge(a, 5, b, 5);
  cout << endl;
}
