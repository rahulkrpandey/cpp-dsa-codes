#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void minFlip(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (nums[i - 1] != nums[i]) {
        int temp = nums[i];
        cout << "from " << (i) << " to";
        while (nums[i] == temp && i < n) {
          nums[i] = nums[i] == 0 ? 1 : 0;
          i++;
        }
        cout << (i - 1) << endl;
      }
    }

    cout << endl;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0};
  s.minFlip(nums);
  for (auto i : nums) cout << i << " ";
  cout << endl;
}
