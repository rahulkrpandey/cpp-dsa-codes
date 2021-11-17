#include <iostream>
using namespace std;

bool isPalindrome(int n) {
  if (n >= 0 && n <= 9) return true;

  int ans = 0, rem = 0, m = n;

  while (n > 0) {
    rem = n % 10;
    ans *= 10;
    ans += rem;
    n /= 10;
  }

  return ans == m;
}

int main() {
  int n;
  cin >> n;
  cout << isPalindrome(n) << endl;
}
