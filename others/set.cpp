#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_set<vector<int>> st(logs.begin(), logs.end());
    //        for (auto it: logs)
    //           st.insert(it);

    unordered_map<int, int> mp;
    for (auto it : st) {
      mp[it[0]]++;
      st.erase(it);
    }

    vector<int> ans(k + 1, 0);
    for (auto it : mp) {
      ans[it.second]++;
      mp.erase(it);
    }
  }
};
