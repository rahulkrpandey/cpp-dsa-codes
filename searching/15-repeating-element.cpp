#include <iostream>
using namespace std;

int find(int* a, int size) {
  int slow = a[0] + 1, fast = a[0] + 1;
  do {
    slow = a[slow] + 1;
    fast = a[fast] + 1;
    fast = a[fast] + 1;
  } while (slow != fast && slow < size && fast < size);

  if (slow == fast) {
    slow = a[0] + 1;
    while (slow != fast) {
      slow = a[slow] + 1;
      fast = a[fast] + 1;
    }

    return slow - 1;
  }

  return -1;
}

int main() {
  int a[] = {0, 1, 3, 2, 3, 3, 5, 4, 3, 0};

  cout << find(a, 10) << endl;
}
