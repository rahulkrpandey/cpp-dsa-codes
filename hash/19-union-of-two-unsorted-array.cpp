#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

typedef class unionArray {
 public:
  int findUnion(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> s;

    for (int i = 0; i < nums1.size(); i++) s.insert(nums1[i]);
    for (int i = 0; i < nums2.size(); i++) s.insert(nums2[i]);

    return s.size();
  }
} itr;

int main() {
  itr i;
  vector<int> a = {1, 3, 2, 2, 3, 4};
  vector<int> b = {10, 30, 20, 20, 30, 40, 10};
  cout << i.findUnion(a, b) << endl;
}
