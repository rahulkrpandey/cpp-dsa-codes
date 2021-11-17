#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
	public:
		void prevGreatest(vector<int> nums) {
			stack<int> sk;
			sk.push(nums[0]);
			cout << -1 << " ";
			for (int i=1; i<nums.size(); i++) {
				while (!sk.empty() && nums[i]>=sk.top())
					sk.pop();
				if (sk.empty()) cout << -1 << " ";
				else cout << sk.top() << " ";
				sk.push(nums[i]);
			}
			cout << endl;
		}
};

int main() {
	Solution s;
	vector<int> nums={15, 10, 18, 12, 4, 6, 2, 8};
	s.prevGreatest(nums);
	vector<int> nums1={8, 10, 12};
	s.prevGreatest(nums1);
}

