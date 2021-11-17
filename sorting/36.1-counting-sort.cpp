#include <iostream>
using namespace std;

void countSort(int a[], int size, int k) {
  int count[k], output[size];
  for (int i = 0; i < k; i++) count[i] = 0;

  for (int i = 0; i < size; i++) count[a[i]]++;

  for (int i = 1; i < k; i++) count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[a[i]] - 1] = a[i];
    count[a[i]]--;
  }

  for (int i = 0; i < size; i++) a[i] = output[i];
}

int main() {
  int a[] = {1, 3, 0, 4, 3, 4, 1, 3, 2};
  int k = 5;

  countSort(a, 9, k);

  for (int i = 0; i < 9; i++) cout << a[i] << " ";

  cout << endl;
}
