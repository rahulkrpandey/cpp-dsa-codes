#include <algorithm>
#include <iostream>
using namespace std;

class interval {
 public:
  int start;
  int end;
};

bool myComp(interval x, interval y) { return x.end > y.end; }

void mergeAndPrint(interval a[], int size) {
  sort(a, a + size, myComp);
  int res = 0;

  for (int i = 1; i < size; i++) {
    if (a[i].end >= a[res].start) {
      a[res].start = min(a[res].start, a[i].start);
      a[res].end = max(a[res].end, a[i].end);
    } else {
      a[++res] = a[i];
    }
  }

  for (int i = 0; i < res + 1; i++) {
    printf("%d and %d, ", a[i].start, a[i].end);
  }

  cout << endl;
}

int main() {
  interval a[] = {{1, 3}, {2, 4}, {5, 7}, {6, 8}};

  mergeAndPrint(a, 4);
}
