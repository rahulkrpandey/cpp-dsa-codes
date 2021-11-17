#include <iostream>
#include <unordered_set>
using namespace std;

class solution {
 public:
  bool pairSum(int nums[], int n, int sum) {
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
      if (st.find(sum - nums[i]) != st.end()) return true;

      st.insert(nums[i]);
    }
    return false;
  }
};

int main() {
  solution s;
  int nums[] = {3, 2, 8, 15, -8};
  cout << s.pairSum(nums, 5, 0) << endl;
  cout << s.pairSum(nums, 5, 17) << endl;
  cout << s.pairSum(nums, 5, -1) << endl;
}
