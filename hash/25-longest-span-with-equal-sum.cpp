#include <iostream>
#include <unordered_map>
using namespace std;

class solution {
 public:
  int subArray(int nums1[], int nums2[], int n) {
    for (int i = 0; i < n; i++) nums1[i] -= nums2[i];

    unordered_map<int, int> mp;
    int preSum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      preSum += nums1[i];
      if (preSum == 0) ans = i + 1;

      if (mp.find(preSum) == mp.end()) mp.insert({preSum, i});

      if (mp.find(preSum) != mp.end()) ans = max(ans, i - mp[preSum]);
    }

    return ans;
  }
};

int main() {
  solution s;
  int bin1[] = {0, 1, 0, 0, 0, 0};
  int bin2[] = {1, 0, 1, 0, 0, 1};
  cout << s.subArray(bin1, bin2, 6) << endl;

  int bin3[] = {0, 1, 0, 1, 1, 1, 1};
  int bin4[] = {1, 1, 1, 1, 1, 0, 1};
  cout << s.subArray(bin3, bin4, 7) << endl;

  int bin5[] = {1, 1, 1};
  int bin6[] = {0, 0, 0};
  cout << s.subArray(bin5, bin6, 3) << endl;

  int bin7[] = {0, 0, 1, 0};
  int bin8[] = {1, 1, 1, 1};
  cout << s.subArray(bin7, bin8, 4) << endl;
}
