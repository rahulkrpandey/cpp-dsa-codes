#include <iostream>
#include <unordered_map>
using namespace std;

class solution {
 public:
  int lSubarray(int nums[], int n, int sum) {
    unordered_map<int, int> mp;
    int prefix_sum = 0, ln = 0;

    for (int i = 0; i < n; i++) {
      prefix_sum += nums[i];
      if (prefix_sum == sum) ln = i + 1;

      if (mp.find(prefix_sum) == mp.end()) mp.insert({prefix_sum, i});

      if (mp.find(prefix_sum - sum) != mp.end())
        ln = max(ln, i - mp[prefix_sum - sum]);
    }

    return ln;
  }
};

int main() {
  solution s;
  int nums[] = {5, 8, -4, -4, 9, -2, -2};
  cout << s.lSubarray(nums, 7, 0) << endl;
  int nums1[] = {3, 1, 0, 1, 8, 2, 3, 6};
  cout << s.lSubarray(nums1, 8, 5) << endl;
  int nums2[] = {8, 3, 7};
  cout << s.lSubarray(nums2, 3, 15) << endl;
  int nums3[] = {8, 3, 1, 5, -6, 6, 2, 2};
  cout << s.lSubarray(nums3, 8, 4) << endl;
}
