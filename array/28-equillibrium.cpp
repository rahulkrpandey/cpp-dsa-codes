#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int nfindEquillibrium(vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1) return -1;

    vector<int> sum(n, 0);
    for (int i = 0; i < n; i++) {
      if (i == 0)
        sum[i] = nums[i];
      else
        sum[i] = sum[i - 1] + nums[i];
    }

    for (int i = 0; i < n; i++) {
      int lSum = (i == 0) ? 0 : sum[i - 1];
      int rSum = (i == n - 1) ? 0 : sum[n - 1] - sum[i];
      if (lSum == rSum) return i;
    }
    return -1;
  }

  int findEquillibrium(vector<int>& nums) {
    int n = nums.size();
    if (n == 0 || n == 1) return -1;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += nums[i];

    int lSum = 0;
    for (int i = 0; i < n; i++) {
      lSum = (i == 0) ? 0 : lSum + nums[i - 1];
      if (lSum == sum - lSum - nums[i]) return i;
    }

    return -1;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 3, 5, -6, 20, 3, 0};
  cout << s.findEquillibrium(nums) << endl;
}
