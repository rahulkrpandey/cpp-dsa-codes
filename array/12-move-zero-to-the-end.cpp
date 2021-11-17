#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void moveToRight(vector<int>& nums) {
    if (nums.size() == 0 || nums.size() == 1) return;
    int count = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[count]);
        count++;
      }
    }
  }
};

int main() {
  Solution s;
  vector<int> nums = {0, 0};
  s.moveToRight(nums);
  for (auto it : nums) cout << it << " ";
  cout << endl;
}
