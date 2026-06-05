#include <bits/stdc++.h>
using namespace std;
/*
Given a function f(x) which is unimodal ( for example,a downward parabola, the
slope is a decreasing function, has exactly one peak).


we want to find the value of x for which f(x) is maximum
*/
double f(double x) { return 5 - (x - 1.732) * (x - 1.732); }
int main() {
  double l = 0, r = 10;
  // we narrow down our search space until the only point that is left in our
  // search space is the vertex
  while (r - l > 1e-6) {
    double m1 = (2 * l + r) / 3;
    double m2 = (l + 2 * r) / 3;
    /*
        three cases
    ->f(m1)>f(m2): we can eliminate the range [m2,r] because [m2,r] lies in
       the decreasing portion, and we know that, vertex does not lie in this
       strictly decreasing portion
    ->f(m1)=f(m2): we can eliminate both [m2,r] and [l,m1] due to a similar
        reason
    -> f(m1)<f(m2): we can eliminate [l,m1]
    */
    double f_m1 = f(m1);
    double f_m2 = f(m2);
    if (f_m1 > f_m2) {
      r = m2;
    } else if (f_m1 == f_m2) {
      l = m1;
      r = m2;
    } else {
      l = m1;
    }
  }
  // at the end, we have x=l as the vertex of the parabola!
  cout << l << " " << f(l) << endl;
}