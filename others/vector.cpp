#include <iostream>
#include <vector>
using namespace std;

class solution {
 public:
  void fn() {
    vector<vector<int>> ans;
    vector<int> temp;

    ans[0].push_back(1);
    ans[0].push_back(2);
    ans[1].push_back(3);
    ans[1].push_back(4);
    ans[2].push_back(5);
    ans[2].push_back(6);
    ans[3].push_back(7);
    ans[3].push_back(8);

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 6; j++) cout << ans[i][j] << " ";
      cout << endl;
    }

    cout << endl;
  }
};

int main() {
  solution s;
  s.fn();
}
