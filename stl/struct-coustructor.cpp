#include <iostream>
using namespace std;

typedef struct students {
  int rno;
  int marks;
  string name;
  students(int rn, int mar, string nam) {
    rno = rn;
    marks = mar;
    name = nam;
  }

  void display() { cout << rno << " " << marks << " " << name << endl; }
} stu;

int main() {
  stu* s1 = new stu(21, 88, "rahul pandey");
  stu* s2 = new stu(19, 75, "raghu rajan");
  s1->display();
  s2->display();
  delete s1;
  delete s2;
}
