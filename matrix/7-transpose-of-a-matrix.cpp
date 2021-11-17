#include <iostream>
using namespace std;

void transpose(int a[4][4]) {
  int n = 4;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = a[i][j];
      a[i][j] = a[j][i];
      a[j][i] = temp;
    }
  }
}

int main() {
  int a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cout << a[i][j] << " ";
    cout << endl;
  }

  transpose(a);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cout << a[i][j] << " ";
    cout << endl;
  }
}
