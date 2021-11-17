#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class solution {
 public:
  void printFrequency(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto it : nums) m[it]++;

    for (auto it : m) cout << it.first << " " << it.second << endl;

    cout << endl;
  }
};

int main() {
  vector<int> a = {2, 2, 1, 4, 1, 5, 4, 5, 6, 11, 12, 1, 11, 12};
  solution* s;
  s->printFrequency(a);
}
