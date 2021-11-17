#include <iostream>
using namespace std;

void swap(int* a, int i, int j) {
  int temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}

void bubble(int* a, int size) {
  for (int i = 0; i < size - 1; i++) {
    bool Swap = false;
    for (int j = i + 1; j < size - i; j++) {
      if (a[j] < a[j - 1]) {
        swap(a, j, j - 1);
        Swap = true;
      }
    }

    if (Swap == false) break;
  }
}

int main() {
  int a[] = {1, 10, 5, 7, 9, 8};

  bubble(a, 6);

  for (int i = 0; i < 6; i++) cout << a[i] << " ";

  cout << endl;
}
