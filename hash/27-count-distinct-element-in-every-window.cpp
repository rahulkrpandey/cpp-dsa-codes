#include <iostream>
#include <unordered_map>
using namespace std;

class solution {
 public:
  void window(int nums[], int n, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++) mp[nums[i]]++;

    for (int i = 0; i < n - k; i++) {
      cout << mp.size() << " ";

      if (nums[i] == 1)
        mp.erase(nums[i]);
      else
        mp[nums[i]]--;

      mp[i + k - 1]++;
    }
    cout << endl;
  }
};

int main() {
  solution s;
  int nums[] = {10, 20, 10, 10, 30, 40};
  s.window(nums, 6, 4);
}
