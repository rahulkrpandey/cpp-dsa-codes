#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  void nprintFrequencies(vector<int>& nums) {
    int count = 1, i = 0;
    if (nums.size() == 1) printf("%d -> %d\n", nums[0], 1);

    for (i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        printf("%d -> %d\n", nums[i - 1], count);
        count = 0;
      }

      count++;
    }

    printf("%d -> %d\n", nums[i - 1], count);
    cout << endl;
  }
};

int main() {
  Solution s;
  vector<int> nums = {10, 20, 30};
  s.printFrequencies(nums);
}
