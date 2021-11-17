#include<iostream>
#include<stack>
using namespace std;

class Solution {
  public:
    bool isMatched(char a, char b) {
      if (a=='(') return b==')';
      else if (a=='[') return b==']';
      else return b=='}';
    }

    bool isBalanced(string& str) {
      stack<char> sk;
      for (int i=0; str[i] != '\0'; i++) {
        if (str[i] == '(' || str[i] == '[' || str[i]=='{')
          sk.push(str[i]);
        else {
          if (sk.empty()) return false;
          char ch=str[i], tp=sk.top();
          if (!isMatched(tp, ch)) return false;
          sk.pop();
        }
      }

      return sk.empty();
    }
};

int main() {
  Solution s;
  string str="({[]})";
  string ktr="([]})";
  string st="(){[{()}]}";
  cout << s.isBalanced(str) << endl;
  cout << s.isBalanced(ktr) << endl;
  cout << s.isBalanced(st) << endl;
}
