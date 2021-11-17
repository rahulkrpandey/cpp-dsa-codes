#include <limits.h>
#include <iostream>
#include <vector>
#define Min(x, y) (x < y) ? x : y
using namespace std;

class Solution {
  const int CHAR = 256;

 public:
  int aleftmostRepeatedCharacter(const string& str) {
    if (str.size() == 0) return -1;
    vector<int> count(CHAR, 0);
    for (int i = 0; i < str.length(); i++) count[str[i]]++;

    for (int i = 0; i < str.length(); i++)
      if (count[str[i]] > 1) return i;

    return -1;
  }

  int bleftmostRepeatedCharacter(const string& str) {
    if (str.size() == 0) return -1;
    vector<int> fidx(CHAR, -1);
    int ans = INT_MAX;

    for (int i = 0; i < str.size(); i++) {
      if (fidx[str[i]] == -1)
        fidx[str[i]] = i;

      else {
        ans = Min(ans, fidx[str[i]]);
      }
    }

    return ans;
  }

  int cleftmostRepeatedCharacter(const string& str) {
    if (str.length() == -1) return -1;
    vector<bool> isVisited(CHAR, false);
    int ans = -1;

    for (int i = str.length() - 1; i >= 0; i--) {
      if (isVisited[str[i]])
        ans = i;

      else
        isVisited[str[i]] = true;
    }

    return ans;
  }
};

int main() {
  Solution s;
  string str = "abcdttia";

  cout << s.cleftmostRepeatedCharacter(str) << endl;
}
