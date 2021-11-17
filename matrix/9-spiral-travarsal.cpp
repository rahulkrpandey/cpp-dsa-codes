S#include <iostream>
#include <vector>
using namespace std;

void spiral(vector<vector<int>> a, int R, int C) {
  int top = 0, bottom = R - 1, right = C - 1, left = 0;

  while (top <= bottom && left <= right) {
    for (int i = left; i <= right; i++) cout << a[top][i] << " ";

    top++;

    for (int i = top; i <= bottom; i++) cout << a[i][right] << " ";

    right--;

    if (top <= bottom && left <= right) {
      for (int i = right; i >= left; i--) cout << a[bottom][i] << " ";

      bottom--;
    }

    if (left <= right && top <= bottom) {
      for (int i = bottom; i >= top; i--) cout << a[i][left] << " ";

      left++;
    }
  }
}

int main() {
  vector<vector<int>> a = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> b = {{1, 2, 3}, {4, 5, 6}};
  vector<vector<int>> c = {{10, 20, 30}};
  vector<vector<int>> d = {{10}, {20}, {30}};

  spiral(a, 4, 4);
  cout << endl;
  spiral(b, 2, 3);
  cout << endl;
  spiral(c, 1, 3);
  cout << endl;
  spiral(d, 3, 1);
  cout << endl;
}
