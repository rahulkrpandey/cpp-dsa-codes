#include <iostream>
using namespace std;

class timeFormat {
 public:
  string changeFormat(string& time) {
    if (time.size() < 10) {
      cout << "Wrong input\n";
      return "~~:~~:~~xx";
    }
    string sub1 = time.substr(0, 2);
    string sub2 = time.substr(8, 2);

    if (sub2 == "PM" || sub2 == "pm") {
      if (sub1 == "12") {
        time[0] = '0';
        time[1] = '0';
      }

      else {
        time[0] += 1;
        time[1] += 2;
      }
    }

    time = time.substr(0, 8);
    return time;
  }
};

int main() {
  timeFormat t;
  string t1 = "11:44:46AM";
  string t2 = "04:00:00PM";
  string t3 = "12:44:46PM";
  string t4 = "04:50:00AM";
  string t5 = "11:44:46PM";
  cout << t.changeFormat(t1) << endl;
  cout << t.changeFormat(t2) << endl;
  cout << t.changeFormat(t3) << endl;
  cout << t.changeFormat(t4) << endl;
  cout << t.changeFormat(t5) << endl;
}
