#include <algorithm>
#include <iostream>
using namespace std;

void swap(int* A, int i, int j) {
  int temp = A[i];
  A[i] = A[j];
  A[j] = temp;
}

void bubblesort(int* A, int size) {
  for (int i = 0; i < size - 1; i++) {
    bool Swap = false;
    for (int j = 1; j < size - i; j++) {
      if (A[j] < A[j - 1]) {
        swap(A, j, j - 1);
        Swap = true;
      }
    }

    if (Swap == false) break;
  }
}

int main() {
  int A[] = {10, 9, 7, 6, 5, 4, 3, 2, 1};
  int b[] = {1, 2, 3, 4, 5};
  bubblesort(b, 5);

  for (int i = 0; i < 5; i++) {
    cout << b[i] << " ";
  }

  return 0;
}
