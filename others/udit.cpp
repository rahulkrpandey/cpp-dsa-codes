// AUTOMATICALLY GIVE ALL ROOT
#include <cmath>
#include <iostream>
using namespace std;

double f(double X) {
  // return X*X-4.3*X+4.62;
  // return X*X*X-X-11;
  // return X*X*X-9*X*X+26*X-24;
  // return X*X*X-12*X*X+44*X-48;
  // return X*X*X*X*X*X*X-2502.21*X*X*X*X*X+5526.21*X*X*X-3025*X;
  return X;
}
int main() {
  double a = -100, b, c, Pre = 0.00001;
  double i = -99;

  for (int j = 1; j <= 10; j++) {
    if (!(j == 1)) {
      i = i - (j - 1) * Pre;
      // i=i-Pre;
      a = i;
    }

    while (f(i) * f(a) > 0 && i <= 100) {
      a = i - Pre;
      i += 0.1;
    }
    if (i > 100) {
      cout << "No Other Real Root within limit(-99 to 100)";
      break;
    } else {
      // b=a+1+2*Pre;
      b = i - Pre;
      cout << "j : " << j << endl;
      cout << "i : " << i << endl;
      cout << "a : " << a << endl;
      cout << "b : " << b << endl;

      do {
        c = (a + b) / 2;
        // cout <<c<<endl;

        if (f(c) > 0) {
          if (f(a) > 0) {
            a = c;
          } else if (f(b) > 0) {
            b = c;
          }
        } else if (f(c) < 0) {
          if (f(a) < 0) {
            a = c;
          } else if (f(b) < 0) {
            b = c;
          }
        } else
          break;
      } while ((fabs(c) + 2 * Pre > floor(c) + Pre) && (f(a) * f(b)) < 0);

      int j = 0;
      if (!(f(a) * f(b) > 0))
        cout << "Root " << j << " : " << floor(c) << endl << endl;

      else {
        cout << "No Root" << endl;
      }
    }
  }
  return 0;
}
