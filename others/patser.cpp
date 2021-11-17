#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void patSer(string txt, string pat) {
    int d = 5, n = txt.size(), m = pat.size();
    int t = 0, h = 0, p = 1, q = 97;
    for (int i = 1; i < m; i++) {
      p *= d % q;
    }
    for (int i = 0; i < m; i++) {
      t = (t * d + pat[i]) % q;
      h = (h * d + txt[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
      if (h == t) {
        bool flag = true;
        for (int j = 0; j < m; j++)
          if (txt[i + j] != pat[j]) {
            flag = false;
            break;
          }

        if (flag) cout << i << " ";
      }

      if (i < n - m) {
        h = ((h - txt[i] * p) * d + txt[i + m]) % q;
        if (h < 0) h = h + q;
      }
    }

    cout << endl;
  }
};

int main() {
  string str = "abcabcabcabcd";
  string pat = "abcd";
  Solution s;
  s.patSer(str, pat);
}
