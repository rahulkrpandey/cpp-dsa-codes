#include <iostream>
#include <unordered_set>
using namespace std;

class solution {
 public:
  bool zeroSum(int nums[], int n) {
    unordered_set<int> st;
    int prefixSum = 0;

    for (int i = 0; i < n; i++) {
      prefixSum += nums[i];
      if (st.find(prefixSum) != st.end()) return true;
      if (prefixSum == 0) return true;

      st.insert(prefixSum);
    }

    return false;
  }
};

int main() {
  solution s;
  int nums[] = {1, 4, 13, -3, -10, 5};
  cout << s.zeroSum(nums, 6) << endl;
  int nums1[] = {-1, 4, -3, 5, 1};
  cout << s.zeroSum(nums1, 5) << endl;
  int nums2[] = {3, 1, -2, 5, 6};
  cout << s.zeroSum(nums2, 5) << endl;
  int nums3[] = {5, 6, 0, 8};
  cout << s.zeroSum(nums3, 4) << endl;
}
