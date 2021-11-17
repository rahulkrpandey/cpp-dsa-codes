#include <iostream>
using namespace std;

void insertsort(int* A, int size) {
  for (int i = 1; i < size; i++) {
    int j = i - 1;
    int temp = A[i];
    while (A[j] > temp && j >= 0) {
      A[j + 1] = A[j];
      j--;
    }

    A[j + 1] = temp;
  }
}

int main() {
  int a[] = {6, 5, 4, 3, 2, 1};
  insertsort(a, 6);

  for (int i = 0; i < 6; i++) {
    cout << a[i] << " " << endl;
  }
}
