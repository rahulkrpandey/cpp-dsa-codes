#include <iostream>
#include <unordered_set>
using namespace std;

class solution {
 public:
  bool subarraySum(int nums[], int n) {
    unordered_set<int> st;

    int preSum = 0;
    for (int i = 0; i < n; i++) {
      preSum += nums[i];
      if (preSum == 0) return true;

      if (st.find(preSum) != st.end()) return true;

      st.insert(preSum);
    }

    return false;
  }
};

int main() {
  solution s;
  int nums[] = {4, 1, 3, 3, 5, 2};
  int nums1[] = {2, 1, 5, 2, 8, 9};
  int nums2[] = {7, 3, 5, 5};

  cout << s.subarraySum(nums, 6) << endl;
  cout << s.subarraySum(nums1, 6) << endl;
  cout << s.subarraySum(nums2, 4) << endl;
}
