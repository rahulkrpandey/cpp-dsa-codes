#include <iostream>
using namespace std;

class Solution {
 public:
  // naive algo, O[n^2]
  void asearchPattern(string txt, string pat) {
    int n = txt.length(), m = pat.length();

    for (int i = 0; i <= n - m; i++) {
      bool flag = true;
      for (int j = 0; j < m; j++)
        if (txt[i + j] != pat[j]) {
          flag = false;
          break;
        }

      if (flag) cout << i << " ";
    }
    cout << endl;
  }

  // Improved naive, character in patter are different, overall O[n]
  void searchPattern(string txt, string pat) {
    int n = txt.length(), m = pat.length();
    for (int i = 0; i <= n - m;) {
      int j;
      for (j = 0; j < m; j++)
        if (txt[j + i] != pat[j]) break;

      if (j == m) cout << i << ' ';
      if (j == 0)
        i++;
      else
        i += j;
    }
    cout << endl;
  }
};

int main() {
  Solution s;
  s.searchPattern("abababcd", "ab");
  s.searchPattern("abcabcd", "abcd");
  s.searchPattern("aaaaa", "a");
  s.searchPattern("abcde", "ac");
}
