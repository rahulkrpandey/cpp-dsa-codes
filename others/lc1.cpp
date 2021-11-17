#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_set<int> st;
    for (int i = 0; i < groupSizes.size(); i++) st.insert(groupSizes[i]);

    vector<vector<int>> ans(st.size());
    int j = 0;
    for (auto it : st) {
      ans.push_back(vector<int>);
      i for (int i = 0; i < groupSizes.size(); i++) {
        if (groupSizes[i] == it) ans[j].push_back(i);

        if (temp.size() == it) break;
      }

      j++;
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> groupSizes = {3, 3, 3, 3, 3, 3, 1};
  vector<vector<int>> ans = s.groupThePeople(groupSizes);

  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";

    cout << endl;
  }
}
