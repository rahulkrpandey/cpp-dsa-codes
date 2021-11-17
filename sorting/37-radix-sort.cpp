#include <iostream>
using namespace std;

void countSort(int a[], int size, int exp) {
  int count[10], output[size];

  for (int i = 0; i < 10; i++) count[i] = 0;

  for (int i = 0; i < size; i++) count[(a[i] / exp) % 10]++;

  for (int i = 1; i < 10; i++) count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(a[i] / exp) % 10] - 1] = a[i];
    count[(a[i] / exp) % 10]--;
  }

  for (int i = 0; i < size; i++) a[i] = output[i];
}

void radixSort(int a[], int size) {
  int max = a[0];
  for (int i = 1; i < size; i++)
    if (a[i] > max) max = a[i];

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countSort(a, size, exp);
  }
}

int main() {
  int a[] = {319, 212, 6, 8, 100, 50};

  radixSort(a, 6);

  for (int i = 0; i < 6; i++) cout << a[i] << " ";

  cout << endl;
}
