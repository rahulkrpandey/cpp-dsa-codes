#include <iostream>
#include <unordered_set>
using namespace std;

class solution {
 public:
  bool givenSum(int nums[], int n, int sum) {
    unordered_set<int> st;
    int prefix_sum = 0;
    for (int i = 0; i < n; i++) {
      prefix_sum += nums[i];

      if (st.find(prefix_sum - sum) != st.end()) return true;
      if (prefix_sum == sum) return true;

      st.insert(prefix_sum);
    }
    return false;
  }
};

int main() {
  solution s;
  int nums[] = {5, 8, 6, 13, 3, -1};
  cout << s.givenSum(nums, 6, 22) << endl;
}
