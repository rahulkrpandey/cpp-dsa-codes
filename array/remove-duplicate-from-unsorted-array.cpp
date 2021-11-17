#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      int idx = nums[i] < 0 ? -nums[i] - 1 : nums[i] - 1;
      if (nums[idx] > 0) nums[idx] *= -1;
    }

    vector<int> ans;
    for (int i = 0; i < n; i++)
      if (nums[i] > 0) ans.push_back(i + 1);

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {5, 1, 4, 3, 3};
  vector<int> ans = s.removeDuplicates(nums);
  for (int i : ans) cout << i << " ";
  cout << endl;
}
