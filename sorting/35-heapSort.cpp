#include <iostream>
using namespace std;

void buildHeap(int a[], int size);
void heapify(int a[], int size, int i);
void heapSort(int a[], int size);
void swap(int a[], int i, int j);

int main() {
  int a[] = {1, 3, 5, 2, 4, 6, 9, 8};
  heapSort(a, 8);

  for (int i = 0; i < 8; i++) cout << a[i] << " ";

  cout << endl;
}

void buildHeap(int a[], int size) {
  for (int i = (size - 2) / 2; i >= 0; i--) {
    heapify(a, size, i);
  }
}

void heapify(int a[], int size, int i) {
  int largest = i, l = 2 * i + 1, r = 2 * i + 2;

  if (l < size && a[l] > a[largest]) largest = l;

  if (r < size && a[r] > a[largest]) largest = r;

  if (largest != i) {
    swap(a, i, largest);
    heapify(a, size, largest);
  }
}

void swap(int a[], int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void heapSort(int a[], int size) {
  buildHeap(a, size);

  for (int i = size - 1; i >= 1; i--) {
    swap(a, i, 0);
    heapify(a, i, 0);
  }
}
