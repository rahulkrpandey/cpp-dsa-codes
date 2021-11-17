#include <algorithm>
#include <iostream>
using namespace std;

int noOfGuest(int arrival[], int departure[], int n) {
  int i = 0, j = 0, ans = 0, count = 0;
  sort(arrival, arrival + n);
  sort(departure, departure + n);

  while (i < n && j < n) {
    if (arrival[i] <= departure[j]) {
      i++;
      count++;
    } else {
      j++;
      count--;
    }

    ans = max(ans, count);
  }

  return ans;
}

int main() {
  int a[] = {900, 940, 950, 1100, 1500, 1800};
  int b[] = {910, 1200, 1120, 1120, 1900, 2000};

  cout << noOfGuest(a, b, 6) << endl;

  for (int i = 0; i < 6; i++) {
    cout << a[i] << " ";
    cout << b[i] << " " << endl;
  }
}
