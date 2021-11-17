#include <iostream>
#include <unordered_map>
using namespace std;

class solution {
 public:
  int subArray(int binary[], int n) {
    unordered_map<int, int> mp;
    int preSum = 0, ans = 0;
    for (int i = 0; i < n; i++) {
      if (binary[i] == 0)
        preSum -= 1;
      else
        preSum += 1;

      if (preSum == 0) ans = i + 1;
      if (mp.find(preSum) == mp.end()) mp.insert({preSum, i});

      if (mp.find(preSum) != mp.end()) ans = max(ans, i - mp[preSum]);
    }

    return ans;
  }
};

int main() {
  solution s;
  int bin[] = {1, 0, 1, 1, 1, 0, 0};
  cout << s.subArray(bin, 7) << endl;
  int bin1[] = {1, 1, 1, 1};
  cout << s.subArray(bin1, 4) << endl;
  int bin2[] = {0, 0, 1, 1, 1, 1, 1, 0};
  cout << s.subArray(bin2, 8) << endl;
}
