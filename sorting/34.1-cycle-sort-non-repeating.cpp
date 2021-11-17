#include <iostream>
using namespace std;

void swap(int a[], int* item, int i) {
  int temp = *item;
  *item = a[i];
  a[i] = temp;
}

void sort(int a[], int size) {
  for (int cs = 0; cs < size - 1; cs++) {
    int item = a[cs];
    int pos = cs;

    for (int i = cs + 1; i < size; i++)
      if (a[i] < item) pos++;

    swap(a, &item, pos);

    while (pos != cs) {
      pos = cs;

      for (int i = cs + 1; i < size; i++)
        if (a[i] < item) pos++;

      swap(a, &item, pos);
    }
  }
}

int main() {
  int a[] = {1, 3, 5, 2, 4, 6, 9, 8};
  sort(a, 8);

  for (int i = 0; i < 8; i++) cout << a[i] << " ";

  cout << endl;
}
