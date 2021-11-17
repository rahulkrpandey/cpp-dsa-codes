#include <iostream>
using namespace std;

void printBoundry(int **a, int r, int c) {
  if (r == 1) {
    for (int i = 0; i < c; i++) cout << a[0][i] << " ";
  }

  else if (c == 1) {
    for (int i = 0; i < r; i++) cout << a[i][0] << " ";
  }

  else {
    for (int i = 0; i < c; i++) cout << a[0][i] << " ";

    for (int i = 1; i < r - 1; i++) cout << a[i][c - 1] << " ";

    for (int i = c - 1; i >= 0; i--) cout << a[r - 1][i] << " ";

    for (int i = r - 2; i > 0; i--) cout << a[i][0] << " ";
  }
}

int main() {
  int *a[4];
  for (int i = 0; i < 4; i++) a[i] = new int[4];

  int k = 0;
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) a[i][j] = ++k;

  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cout << a[i][j] << " ";
  cout << endl;
  printBoundry(a, 4, 4);

  for (int i = 0; i < 4; i++) delete a[i];
}
