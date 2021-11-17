#include <iostream>

void intersection(int* a, int s1, int* b, int s2) {
  int i = 0, j = 0;
  bool found = false;
  while (i < s1 && j < s2) {
    if (i > 0 && a[i] == a[i - 1]) {
      i++;
      continue;
    }

    if (a[i] == b[j]) {
      std::cout << a[i++] << " ";
      j++;
      found = true;
    } else if (a[i] < b[j]) {
      i++;
    } else
      j++;
  }

  if (found == false) {
    std::cout << " not found\n";
  }
}

int main() {
  int a[] = {1, 2, 2, 3, 3, 3, 5};
  int b[] = {4, 4, 6, 7, 8};

  intersection(a, 7, b, 6);
  std::cout << std::endl;
}
