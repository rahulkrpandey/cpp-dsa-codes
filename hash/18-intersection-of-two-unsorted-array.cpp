#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

typedef class intersection {
 public:
  int findIntersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s;

    for (int it : nums2) s.insert(it);

    int ans = 0;
    for (int it : nums1) {
      if (s.find(it) != s.end()) {
        ans++;
        s.erase(it);
      }
    }

    return ans;
  }
} itr;

int main() {
  itr i;
  vector<int> a = {1, 3, 2, 2, 3, 4};
  vector<int> b = {10, 30, 20, 20, 30, 40, 10};
  cout << i.findIntersection(a, b) << endl;
}
