#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void bucketSort(int a[], int size, int k) {
  int maxVal = a[0];
  for (int i = 1; i < size; i++)
    if (a[i] > maxVal) maxVal = a[i];

  maxVal++;
  vector<int> bkt[k];
  for (int i = 0; i < size; i++) {
    int bi = (k * a[i]) / maxVal;
    bkt[bi].push_back(a[i]);
  }

  for (int i = 0; i < k; i++) sort(bkt[i].begin(), bkt[i].end());

  int index = 0;
  for (int i = 0; i < k; i++)
    for (int j = 0; j < bkt[i].size(); j++) a[index++] = bkt[i][j];
}

int main() {
  int a[] = {1, 21, 3, 12, 2, 33, 22, 11, 31, 32, 13, 23};

  bucketSort(a, 12, 4);

  for (int i = 0; i < 12; i++) cout << a[i] << " ";

  cout << endl;
}
