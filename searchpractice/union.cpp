#include <iostream>

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

    if (a[i] == b[j]) {
      std::cout << a[i++] << " ";
      j++;
    } else if (a[i] < b[j]) {
      std::cout << a[i++] << " ";
    } else
      std::cout << b[j++] << " ";
  }

  while (i < s1) {
    if (i > 0 && a[i] == a[i - 1]) {
      i++;
      continue;
    }

    std::cout << a[i++] << " ";
  }

  while (j < s2) {
    if (j > 0 && b[j] == b[j - 1]) {
      j++;
      continue;
    }

    std::cout << b[j++] << " ";
  }
}

int main() {
  int a[] = {1, 2, 3, 3, 4, 6};
  int b[] = {1, 4, 5, 7};
  Union(a, 6, b, 4);
  std::cout << std::endl;
}
