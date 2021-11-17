#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  bool maxSum(vector<int>& nums, int k) {
    int sum = 0, n = nums.size(), j = 0, i = 0;
    while (i < n) {
      if (sum == k)
        return true;
      else if (sum + nums[i] <= k) {
        sum += nums[i++];
      } else
        sum -= nums[j++];
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 0, 20, 3, 10, 15};
  cout << s.maxSum(nums, 0) << endl;
}
