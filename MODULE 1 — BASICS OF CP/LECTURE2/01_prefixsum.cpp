#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of N integers. You will be asked Q queries. Each
query provides two indices L and R. For every query, compute the sum of all
elements in the array from index L to R
*/
signed main() {
  // so for each query, we visit , L,L+1....R and sum their values
  // in total, this will use up R-L+1 operations per query.
  // Q*(R-L+1) operations in total

  // Q->2*10^5, N->2*10^5-> 4*10^10 operations in total if we use the above
  // method

  //[L,R]=[1,R]-[1,L-1]

  // Sum of values at indices [1,R]=a1+a2...ar

  // say the question asks al+al+1.....ar, then we compute
  // (a1+a2.....ar)-(a1+ar.....al-1)

  int n, q;
  cin >> n >> q;
  vector<int> v(n);
  // int-> can carry values upto 2*10^9
  // int cannot actually carry the sum of loads of ints
  // long long-> can carry values upto 2*10^18
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<long long> prefsum;
  prefsum.push_back(0);
  // prefsum[0]=0
  // prefsum[1]=a1
  // prefsum[2]=a1+a2....
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += v[i];
    // sum will contain sum of v[0]....v[i]
    prefsum.push_back(sum);
  } // prefsum has a size of n+1
  for (int query = 0; query < q; query++) {
    int l, r;
    cin >> l >> r; // l=1 implies a_l which is the first element
    long long term1 = prefsum[r];
    long long term2 = prefsum[l - 1];
    cout << term1 - term2 << endl;
  }
  return 0;
}
