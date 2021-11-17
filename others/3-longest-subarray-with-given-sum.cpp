#include <iostream>
#include <unordered_map>
using namespace std;

class solution {
 public:
  int subarraySum(int nums[], int size, int sum = 0) {
    unordered_map<int, int> mp;
    int preSum = 0, ans = 0;
    for (int i = 0; i < size; i++) {
      preSum += nums[i];

      if (preSum == sum) ans = i + 1;

      if (mp.find(preSum) == mp.end()) mp.insert({preSum, i});

      if (mp.find(preSum - sum) != mp.end())
        ans = max(ans, i - mp[preSum - sum]);
    }

    return ans;
  }
};

int main() {
  solution s;
  int nums1[] = {5, 8, -4, -4, 9, -2, 2};
  cout << s.subarraySum(nums1, 7) << endl;
  int num2[] = {3, 1, 0, 1, 8, 2, 3, 6};
  cout << s.subarraySum(num2, 8, 5) << endl;
  int num3[] = {8, 3, 1, 5, -6, 6, 2, 2};
  cout << s.subarraySum(num3, 8, 4) << endl;
}
