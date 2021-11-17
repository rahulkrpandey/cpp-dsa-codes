#include <iostream>
using namespace std;

class Solution {
 public:
  bool isSubsequence(string s1, string s2) {
    if (s1.size() == 0 && s2.size() == 0) return true;
    if (s1.size() == 0 && s2.size() != 0) return false;
    if (s1.size() != 0 && s2.size() == 0) return true;

    if (s1[0] == s2[0])
      return Solution::isSubsequence(s1.substr(1, s1.size() - 1),
                                     s2.substr(1, s2.size() - 1));
    else
      return Solution::isSubsequence(s1.substr(1, s1.size() - 1), s2);
  }
};

int main() {
  Solution s;
  string s1 = "abcdefbdr";
  string s2 = "bdfr";

  cout << s.isSubsequence(s1, s2) << endl;
  cout << s.isSubsequence(s1, "bard") << endl;
}
