#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  // Naive O(n^2)
  void nprintLeaders(vector<int>& candidates) {
    int n = candidates.size();
    for (int i = 0; i < n; i++) {
      bool isLeader = true;
      for (int j = i + 1; j < n; j++)
        if (candidates[j] >= candidates[i]) {
          isLeader = false;
          break;
        }

      if (isLeader) cout << candidates[i] << " ";
    }

    cout << endl;
  }

  // Efficient solution O(n)
  void printLeaders(vector<int>& candidates) {
    int n = candidates.size();
    int mx = candidates[n - 1];
    cout << mx << " ";
    for (int i = n - 2; i >= 0; i--) {
      if (candidates[i] > mx) {
        cout << candidates[i] << " ";
        mx = candidates[i];
      }
    }

    cout << endl;
  }
};

int main() {
  Solution s;
  vector<int> arr = {7, 10, 4, 6, 5, 2};
  vector<int> arr1 = {7, 10, 4, 10, 6, 5, 2};
  vector<int> arr2 = {10, 20, 30};
  vector<int> arr3 = {30, 20, 10};

  s.printLeaders(arr);
  s.printLeaders(arr1);
  s.printLeaders(arr2);
  s.printLeaders(arr3);
}
