#include <iostream>
using namespace std;

int firstocc(int arr[], int N) {
  int l = 0, r = N - 1, result = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == 1) {
      result = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }

  return result;
}

int lastocc(int arr[], int N) {
  int l = 0, r = N - 1, result = -1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == 1) {
      result = mid;
    }
    l = mid + 1;
  }

  return result;
}

int countOnes(int arr[], int N) {
  int f = 0, l = 0;
  f = firstocc(arr, N);
  l = lastocc(arr, N);

  if (l == f && f == -1) return 0;
  return (l - f + 1);
}

int main() {
  int a[] = {
      0, 0, 0, 0, 0, 0, 1, 1,
  };
  cout << countOnes(a, 8) << endl;
}
