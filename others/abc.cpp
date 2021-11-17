#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

/*class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;

    int l = 1, ans = 1;
    unordered_map<char, int> mp;
    mp.insert({s[0], 1});
    for (int i = 1; i < s.length(); i++) {
      if (mp.find(s[i]) != mp.end()) {
        ans = max(ans, l);
        mp[s[i]]++;

        for (auto it : mp) {
          it.second--;
          if (it.second == 0) mp.erase(it.first);
        }

        l = 1;
      } else {
        l++;
        mp[s[i]]++;
      }
    }
    ans = max(ans, l);

    return ans;
  }
};*/
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    if (s.length() == 1) return 1;

    unordered_set<char> st;
    st.insert(s[0]);

    int j = 0, i = 0, ans = 1;
    for (; j < s.length(); j++) {
      if (j == s.length() - 1) return ans;
      if ((st.find(s[j + 1]) != st.end()) && j < s.length() - 1) {
        // int l = st.size();
        // ans = max(ans, l);
        if (s[j] == s[j + 1]) {
          st.clear();
          st.insert(s[j]);
          i = j + 1;
        } else if (s[i] == s[j + 1]) {
          i++;
        } else {
          for (++i; i < j; i++) {
            if (s[i] == s[j + 1]) break;
            st.erase(s[i]);
          }
          i++;
        }
      }

      else {
        st.insert(s[j + 1]);
        int l = st.size();
        ans = max(ans, l);
      }
    }

    return ans;
  }
};

int main() {
  Solution a;
  string s = "abcabcbd";
  cout << a.lengthOfLongestSubstring(s) << endl;
}
