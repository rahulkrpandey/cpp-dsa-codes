#include <iostream>
#include <vector>
using namespace std;

class Solution {
  const int CHAR = 256;

 public:
  int factorial(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;

    return ans;
  }

  int lexrank(string str) {
    int ans = 1;
    vector<int> ct(CHAR, 0);
    int n = str.length();
    int mul = factorial(n);

    for (int j = 0; j < n; j++) ct[str[j]]++;

    for (int j = 1; j < CHAR; j++) ct[j] += ct[j - 1];

    for (int i = 0; i < n; i++) {
      mul = mul / (n - i);
      ans = ans + mul * (ct[str[i] - 1]);
      for (int j = str[i]; j < CHAR; j++) ct[j]--;
    }
    return ans;
  }
};

int main() {
  Solution s;
  string st = "string";
  cout << s.lexrank(st) << endl;
  cout << s.factorial(5) << endl;
}
