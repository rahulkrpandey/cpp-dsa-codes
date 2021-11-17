#include <iostream>
#include <vector>
using namespace std;

void search(vector<vector<int>> a, int r, int c, int key) {
  int i = 0, j = c - 1;
  if (key > a[r - 1][c - 1] || key < a[0][0]) {
    cout << "not found\n";
    return;
  }

  while (i < r && j >= 0) {
    if (a[i][j] == key) {
      printf("found at (%d, %d) \n", i, j);
      return;
    } else if (key > a[i][j])
      i++;
    else
      j--;
  }

  cout << "not found" << endl;
}

int main() {
  vector<vector<int>> a = {
      {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
  search(a, 4, 4, 29);
  search(a, 4, 4, 17);
  vector<vector<int>> b = {{10, 20}, {30, 40}};
  search(b, 2, 2, 30);
  search(b, 2, 2, 31);
}
