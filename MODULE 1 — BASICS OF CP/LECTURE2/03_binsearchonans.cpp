#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
You have N machines, where the i-th machine takes t_i time to produce one
product. All machines work simultaneously. Find the minimum time required
to produce atleast K products
/*
    say the required ans is T.
    the first machine produces: floor(T/t_1) machines
    the second machine produces......



    we want to find the minimum T such that:


    summation from i=1 to N of floor(T/t_i) >=K


    observation 1:
    as T increases, the LHS also increases

    that means,
    given a T, if we know that LHS is too small, then our actual answer say T_0
        would be greater than T

    and say the LHS is large enough, we know that T_0 <= T


    we binary search on the value of T such that,
    we find the smallest of T that satisfies the given inequality.
/*
*/
int main() {
  int n;
  cin >> n;
  int target;
  cin >> target;
  vector<int> t(n);
  for (int i = 0; i < n; i++)
    cin >> t[i];
  long long low = 0, high = 1e18;
  // log2(1e18)->18* (about 60)
  //  we need to see what value in this range is the actual minimum?
  while (low < high) {
    long long mid = (low + high) / 2;
    long long lhs = 0;
    bool is_lhs_large_enough = false;
    // 5n operations
    for (int i = 0; i < n; i++) {
      lhs += (mid / t[i]);
      // it is possible that lhs exceeds 2*10^18 also,
      if (lhs >= target) {
        is_lhs_large_enough = true;
        break;
      }
    }
    if (is_lhs_large_enough) {
      // then our search space would now be [mid,high]
      // we dont need [low,mid], because we already know that mid is an answer
      // that works
      high = mid;
    } else {
      if (lhs >= target) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
  }
  // finally, we will have low=high=minimum such T such that the summation from
  // i=1 to N of floor(T/t_i) >=X
  /// 60n operations
  cout << low << endl;
  return 0;
}