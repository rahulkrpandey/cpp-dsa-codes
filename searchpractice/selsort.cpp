#include <iostream>
using namespace std;

void swap(int* a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void selsort(int* a, int size) {
  for (int i = 0; i < size - 1; i++) {
    int min = a[i];
    int idx = i;
    for (int j = i + 1; j < size; j++) {
      if (a[j] < min) {
        min = a[j];
        idx = j;
      }
    }

    if (idx != i) {
      swap(a, i, idx);
    }
  }
}

int main() {
  int a[] = {1, 10, 5, 7, 9, 8};

  selsort(a, 6);

  for (int i = 0; i < 6; i++) {
    cout << a[i] << " ";
  }

  cout << endl;
}
