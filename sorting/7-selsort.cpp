#include <iostream>
using namespace std;

void swap(int* A, int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}
/*
void selsort(int* A, int size) {
  for (int i = 0; i < size - 1; i++) {
    int minimum = A[i];
    int idx = i;
    for (int j = i + 1; j < size; j++) {
      if (A[j] < minimum) {
        minimum = A[j];
        idx = j;
      }
    }
    
    if (idx != i)
      swap(A, i, idx);
  }
}*/
void selsort(int* A, int size) {
  for (int i = 0; i < size - 1; i++) {
    int maximum = A[size - i - 1];
    int idx = size - i - 1;
    for (int j = 0; j < size - i - 1; j++) {
      if (A[j] > maximum) {
        maximum = A[j];
        idx = j;
      }
    }
    
    if (idx != (size - i - 1))
      swap(A, size - i - 1, idx);
  }
}

int main() {
  int a[] = {6, 5, 4, 3, 2, 1};
  selsort(a, 6);

  for (int i = 0; i < 6; i++) {
    cout << a[i] << " ";
  }

  return 0;
}
