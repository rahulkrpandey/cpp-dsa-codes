#include <limits.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  const int CHAR = 256;

 public:
  int aleftmostUnrepeatedCharacter(const string& str) {
    int ans = INT_MAX;
    vector<bool> isRepeating(CHAR, false);
    vector<int> firstidx(CHAR, -1);

    for (int i = 0; i < str.length(); i++) {
      if (isRepeating[str[i]])
        continue;

      else if (firstidx[str[i]] != -1) {
        firstidx[str[i]] = -1;
        isRepeating[str[i]] = true;
      }

      else
        firstidx[str[i]] = i;
    }

    for (int i = 0; i < CHAR; i++)
      if (firstidx[i] != -1) ans = min(ans, firstidx[i]);

    return ans;
  }

  int bleftmostUnrepeatedCharacter(const string& str) {
    int fidx[CHAR];
    fill(fidx, fidx + CHAR, -1);
    for (int i = 0; i < str.size(); i++) {
      int fi = str[i];
      if (fidx[fi] == -1)
        fidx[fi] = i;
      else
        fidx[fi] = -2;
    }

    int ans = INT_MAX;
    for (int i = 0; i < CHAR; i++)
      if (fidx[i] >= 0) ans = min(ans, fidx[i]);

    return (ans == INT_MAX) ? -1 : ans;
  }
};

int main() {
  Solution s;
  string s1, s2;
  s1 = "abcabc";
  s2 = "abcbdcae";
  cout << s.bleftmostUnrepeatedCharacter(s1) << endl;
  cout << s.bleftmostUnrepeatedCharacter(s2) << endl;
}
