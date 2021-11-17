#include <iostream>
using namespace std;

class Solution {
 public:
  void reverse(char str[], int i, int j) {
    while (i < j) {
      char temp = str[i];
      str[i] = str[j];
      str[j] = temp;
      i++;
      j--;
    }
  }
  char* reverseWordsInSentence(char str[], int n) {
    if (n == 0 || n == 1) return str;

    int start = 0, end = 0;
    reverse(str, 0, n - 1);
    cout << str << endl;
    for (end = 1; end < n; end++) {
      if (str[end] != ' ') {
        while (str[end] != ' ' && end < n) end++;

        reverse(str, start, end - 1);

        while (str[end] == ' ' && end < n) end++;

        start = end;
      }
    }

    reverse(str, start, n - 1);

    return str;
  }
};

int main() {
  Solution s;
  char str[] = "rahul   kumar  pandey";
  cout << s.reverseWordsInSentence(str, 21) << endl;
  cout << str << endl;
}
