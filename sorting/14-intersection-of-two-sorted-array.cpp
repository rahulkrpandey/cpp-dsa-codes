#include <iostream>
using namespace std;

void intersection(int* a, int s1, int* b, int s2) {
  int i = 0, j = 0;
  /*
    while (i < s1 && j < s2) {
      if (a[i] == b[j]) {
        cout << a[i] << " ";
        int temp = a[i];
        while (a[i] == temp) i++; // my solution
      } else if (a[i] < b[j])
        i++;

      else
        j++;
    }*/

  while (i < s1 && j < s2) {
    if (i > 0 && a[i] == a[i - 1]) {
      i++;
      continue;
    }
    if (a[i] == b[j]) {
      cout << a[i] << " ";
      i++;
      j++;
    } else if (a[i] > b[j])
      j++;
    else
      i++;
  }
}

int main() {
  int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
  int b[] = {5, 10, 10, 15, 30};
  intersection(a, 8, b, 5);
  cout << endl << endl;
  int c[] = {1, 1, 3, 3, 3};
  int d[] = {1, 1, 1, 1, 3, 5, 7};
  intersection(c, 5, d, 7);
}
