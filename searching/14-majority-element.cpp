#include <iostream>
using namespace std;

int majority(int* a, int size) {
  int count = 1, result = 0;

  int i = 1;
  while (i < size) {
    if (a[result] == a[i]) {
      count++;
    } else
      count--;

    if (count == 0) {
      count = 1;
      result = i;
    }

    i++;
  }

  count = 0;
  for (int j = 0; j < size; j++) {
    if (a[j] == a[result]) count++;
  }

  if (count > size / 2)
    return i;
  else
    return -1;
}

int main() {
  int a[] = {8, 8, 6, 6, 6, 4, 6};
  cout << majority(a, 7) << endl;
}
