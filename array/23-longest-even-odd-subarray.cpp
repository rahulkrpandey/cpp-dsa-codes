#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int n1evenOddSubArray(vector<int>& nums) {  // my sol
    int count = 0, ans = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
      if (nums[i] % 2 == 0) {
        for (int j = i; j < n; j += 2) {
          if (nums[j] % 2 == 0 && nums[j + 1] % 2 != 0)
            count += 2;
          else if (nums[j] % 2 == 0) {
            count++;
            break;
          } else
            break;
        }
        ans = max(ans, count);
        count = 0;
      } else {
        for (int j = i; j < n; j += 2) {
          if (nums[j] % 2 != 0 && nums[j + 1] % 2 == 0)
            count += 2;
          else if (nums[j] % 2 != 0) {
            count++;
            break;
          } else
            break;
        }
        ans = max(ans, count);
        count = 0;
      }
    }

    return ans;
  }

  int nevenOddSubArray(vector<int>& nums) {
    int n = nums.size(), ans = 0, count = 0;
    for (int i = 0; i < n; i++) {
      count = 1;
      for (int j = i + 1; j < n; j++) {
        if ((nums[j] % 2 == 0 && nums[j - 1] % 2 != 0) ||
            (nums[j] % 2 != 0 && nums[j - 1] % 2 == 0))
          count++;
        else
          break;
      }

      ans = max(ans, count);
    }

    return ans;
  }

  int evenOddSubArray(vector<int>& nums) {  // kadane's algorithm
    int n = nums.size(), ans = 1, count = 1;
    for (int i = 1; i < n; i++) {
      if ((nums[i] % 2 == 0 && nums[i - 1] % 2 != 0) ||
          (nums[i] % 2 != 0 && nums[i - 1] % 2 == 0)) {
        count++;
        ans = max(ans, count);
      }

      else
        count = 1;
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  cout << s.evenOddSubArray(nums) << endl;
  vector<int> nums2 = {1, 1, 1, 2, 3, 4, 5, 6, 7, 6, 6, 6};
  cout << s.evenOddSubArray(nums2) << endl;
}
