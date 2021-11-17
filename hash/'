#include <iostream>
#include <unordered_map>
using namespace std;

class solution {
 public:
  void voting(int nums[], int n, int k) {
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
      if (mp.find(nums[i]) != mp.end()) mp[nums[i]]++;

      if ((mp.find(nums[i]) == mp.end()) && mp.size() < k)
        mp.insert({nums[i], 1});

      else
        for (auto it = mp.begin(); it != mp.end(); it++) {
          it->second--;
          if (it->second == 0) mp.erase(it);
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
      int count = 0;
      for (int i = 0; i < n; i++)
        if (nums[i] == it->first) count++;

      if (count > n / k) cout << it->first << " ";
    }

    cout << endl;
  }
};

int main() {
  solution s;
  int nums[] = {1, 2, 3, 4};

  s.voting(nums, 4, 3);
}
