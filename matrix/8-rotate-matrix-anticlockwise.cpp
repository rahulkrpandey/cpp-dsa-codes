#include <iostream>
#include <vector>
using namespace std;

int rotate(vector<int> a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int temp = a[i][j];
      a[i][j] = a[j][i];
      a[j][i] = temp;
    }
  }

  for (int i = 0; i < n; i++) {
    int low = 0, high = n - 1;
    while (low < high) {
      int temp = a[low][i];
      a[low][i] = a[high][i];
      a[high][i] = temp;

      low++;
      high--;
    }
  }
  return 0;
}

int main() {
  vector<int> a[] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cout << a[i][j] << " ";

    cout << endl;
  }

  rotate(a, 4);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) cout << a[i][j] << " ";

    cout << endl;
  }
}
