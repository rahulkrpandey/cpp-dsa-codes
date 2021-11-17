#include <iostream>
using namespace std;

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

int sort(int a[], int size) {
  int i = -1, j = size;

  while (true) {
    do {
      i++;
    } while (a[i] < 0);
    do {
      j--;
    } while (a[j] >= 0);

    if (i >= j) return j;

    swap(a, i, j);
  }
}

int main() {
  int a[] = {2, -1, 4, -2, 14, 32, -3, -4};

  sort(a, 8);

  for (int i = 0; i < 8; i++) cout << a[i] << " ";

  cout << endl;
}
