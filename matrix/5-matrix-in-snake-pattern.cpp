#include <iostream>
#include <vector>
using namespace std;

int printMatrix(vector<int> a[], int r) {
  int c = a[0].size();
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (i % 2 == 0) {
        cout << a[i][j] << " ";
      } else {
        cout << a[i][c - j - 1] << " ";
      }
    }
  }
  return 0;
}

int main() {
  vector<int> a[4];
  int k = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) a[i].push_back(k++);
  }

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cout << a[i][j] << " ";
    cout << endl;
  }

  printMatrix(a, 4);
}
