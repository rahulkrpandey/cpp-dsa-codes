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

    while (item == a[pos]) pos++;

    if (pos != cs)
      swap(a, &item, pos);
    else
      continue;

    while (pos != cs) {
      pos = cs;

      for (int i = cs + 1; i < size; i++)
        if (a[i] < item) pos++;

      while (item == a[pos]) pos++;

      if (pos != cs)
        swap(a, &item, pos);
      else
        continue;
    }
  }
}

int main() {
  int a[] = {1, 3, 5, 1, 3, 4, 1, 6, 3, 2, 3, 6};
  sort(a, 12);

  for (int i = 0; i < 12; i++) cout << a[i] << " ";

  cout << endl;
}
