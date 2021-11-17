#include <iostream>
using namespace std;

void Union(int* a, int s1, int* b, int s2) {
  int i = 0, j = 0;

  while (i < s1 && j < s2) {
    if (i > 0 && a[i] == a[i - 1]) {
      i++;
      continue;
    }

    if (j > 0 && b[j] == b[j - 1]) {
      j++;
      continue;
    }

    if (a[i] <= b[j]) {
      cout << a[i++] << " ";
    } else {
      cout << b[j++] << " ";
    }
  }

  while (i < s1) {
    if (i > 0 && a[i] == a[i - 1]) {
      i++;
      continue;
    }

    cout << a[i++] << " ";
  }

  while (i < s1) {
    if (j > 0 && b[j] == b[j - 1]) {
      j++;
      continue;
    }

    cout << b[j++] << " ";
  }
}

int main() {
  int a[] = {2, 8, 9, 10, 15};
  int b[] = {3, 5, 8};
  Union(a, 5, b, 3);
  cout << endl << endl;
  int c[] = {2, 3, 3, 3, 4, 4};
  int d[] = {4, 4};
  Union(c, 6, d, 2);

  return 0;
}
