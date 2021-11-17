#include <iostream>
using namespace std;

class Solution {
 public:
  bool isSubsequence(string s1, string s2) {
    int i = 0, j = 0;
    while (j < s1.length() && i < s2.length()) {
      if (s1[j] != s2[i])
        j++;
      else {
        i++;
        j++;
      }
    }

    if (i >= s2.length())
      return true;
    else
      return false;
  }
};

int main() {
  Solution s;
  string s1 = "abcdefbdr";
  string s2 = "bdfr";

  cout << s.isSubsequence(s1, s2) << endl;
  cout << s.isSubsequence(s1, "bard") << endl;
}
