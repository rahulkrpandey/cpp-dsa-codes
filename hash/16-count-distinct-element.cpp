#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

typedef struct myHash {
  int countDistinct(vector<int>& nums) {
    unordered_set<int> s;
    for (int i = 0; i < nums.size(); i++) s.insert(nums[i]);

    return s.size();
  }
} myHash;

int main() {
  myHash m;
  vector<int> nums(10, 0);
  nums = {3, 3, 1, -1, 2, 1, 4, 5, 11, 13, 13, 13, 15};
  cout << m.countDistinct(nums) << endl;
}
