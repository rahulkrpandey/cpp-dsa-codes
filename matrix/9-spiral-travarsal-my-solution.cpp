#include <iostream>
#include <vector>
using namespace std;

void spiral(vector<vector<int>> a) {
  int rSize = a.size(), cSize = a[0].size();
  int c = 0, r = 0;
  while (rSize > 0 && cSize > 0) {
    if (rSize == 1) {
      for (int j = c; j < cSize; j++) cout << a[r][j] << " ";
    }

    else if (cSize == 1) {
      for (int i = r; i < rSize; i++) cout << a[i][c] << " ";
    }

    else {
      for (int j = c; j < cSize; j++) {
        cout << a[r][j] << " ";
      }

      for (int i = r + 1; i < rSize; i++) {
        cout << a[i][cSize - 1] << " ";
      }

      for (int j = cSize - 2; j >= c; j--) {
        cout << a[rSize - 1][j] << " ";
      }

      for (int i = rSize - 2; i > r; i--) {
        //        cout << endl << i << " " << c;
        cout << a[i][c] << " ";
      }
    }

    rSize -= 1;
    if (r + 1 < rSize) r += 1;
    cSize -= 1;
    if (c + 1 < cSize) c += 1;
  }

  cout << endl;
}

int main() {
  vector<vector<int>> a = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  vector<vector<int>> b = {{1, 2, 3}, {4, 5, 6}};
  vector<vector<int>> c = {{10, 20, 30}};
  vector<vector<int>> d = {{10}, {20}, {30}};

  spiral(a);
  cout << endl;
  spiral(b);
  cout << endl;
  spiral(c);
  cout << endl;
  spiral(d);
  cout << endl;
}
