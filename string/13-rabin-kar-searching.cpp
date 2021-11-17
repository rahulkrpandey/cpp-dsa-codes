#include <iostream>
using namespace std;

class Searching {
 public:
  void printIndex(string txt, string pat) {
    int n = txt.length(), m = pat.length(), d = 5, q = 97;

    int h = 1;
    for (int i = 1; i < m; i++) h *= d % q;

    int t = 0, p = 0;
    for (int i = 0; i < m; i++) {
      p = (p * d + pat[i]) % q;
      t = (t * d + txt[i]) % q;
    }

    for (int i = 0; i < n - m + 1; i++) {
      if (p == t) {
        bool flag = true;
        for (int j = 0; j < m; j++)
          if (txt[i + j] != pat[j]) {
            flag = false;
            break;
          }

        if (flag) cout << i << " ";
      }

      if (i < n - m) {
        t = ((t - txt[i] * h) * d + txt[i + m]) % q;
        if (t < 0) t += q;
      }
    }

    cout << endl;
  }
};

int main() {
  Searching s;
  string str = "abcabcabc";
  string t = "abc";
  s.printIndex(str, t);
}
