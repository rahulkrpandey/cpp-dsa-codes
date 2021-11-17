#include <iostream>
#include <unordered_set>
using namespace std;

class solution {
 public:
  int subArray(int nums[], int n) {
    unordered_set<int> st;
    for (int i = 0; i < n; i++) st.insert(nums[i]);

    int ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
      if (st.find(nums[i] - 1) == st.end()) {
        curr = 1;
        int next = nums[i] + 1;
        while (st.find(next++) != st.end()) {
          curr++;
        }
      }
      ans = max(ans, curr);
    }

    return ans;
  }
};

int main() {
  solution s;
  int nums1[] = {1, 9, 3, 4, 2, 20};
  cout << s.subArray(nums1, 6) << endl;

  int n2[] = {8, 20, 7, 30};
  cout << s.subArray(n2, 4) << endl;

  int n3[] = {10, 20, 30};
  cout << s.subArray(n3, 3) << endl;
}
