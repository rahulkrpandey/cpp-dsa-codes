#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class String {
  const int CHAR = 256;

 public:
  bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) return false;

    unordered_map<char, int> mp;
    for (auto it : s1) mp[it]++;

    for (auto it : s2) {
      if (mp.find(it) != mp.end()) {
        mp[it]--;
        if (mp[it] == 0) mp.erase(it);
      }

      else
        return false;
    }

    if (mp.size() != 0)
      return false;

    else
      return true;
  }

  bool areAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    vector<int> count(CHAR, 0);
    for (int i = 0; i < s1.length(); i++) {
      count[s1[i]]++;
      count[s2[i]]--;
    }

    for (int i = 0; i < CHAR; i++)
      if (count[i] != 0) return false;

    return true;
  }
};

int main() {
  String s;
  string s1 = "rahul pandey";
  string s2 = "hulardey kpn";
  cout << s.areAnagram(s1, s2) << endl;
}
