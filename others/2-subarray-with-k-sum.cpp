#include <iostream>
#include <unordered_set>
using namespace std;

class solution {
 public:
  bool subarraySum(int nums[], int size, int k) {
    unordered_set<int> st;
    int preSum = 0;
    for (int i = 0; i < size; i++) {
      preSum += nums[i];
      if (preSum == k) return true;

      if (st.find(preSum - k) != st.end()) return true;

      st.insert(preSupreSumm);
    }

    return false;
  }
};

int main() {
  solution s;
  int nums1[] = {2, 3, 2, 5, 3, 13};
  cout << s.subarraySum(nums1, 6, 7) << endl;
  cout << s.subarraySum(nums1, 6, 10) << endl;
  cout << s.subarraySum(nums1, 6, 16) << endl;
  cout << s.subarraySum(nums1, 6, 17) << endl;
}
