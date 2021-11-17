#include <iostream>
using namespace std;

void insertsort(int* a, int size) {
  for (int i = 0; i < size; i++) {
    int temp = a[i];
    int j = i - 1;
    while (a[j] > temp && j >= 0) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = temp;
  }
}

int main() {
  int a[] = {1, 10, 3, 5, 7, 9, 8};

  insertsort(a, 7);

  for (int i = 0; i < 7; i++) cout << a[i] << " ";

  cout << endl;
}
