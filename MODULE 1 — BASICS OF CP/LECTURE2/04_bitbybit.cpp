#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
you can represent uniquely as a sum of power of 2's

for example


35=32+2+1=2^5+2^1+2^0
17=16+1=

18-> 9 0
4

2 0



0000010010

say 35 is an 8-bit integer
00100011-> binary representation of 35
00010001-> binary representation of 17

&->a&b->00000001->1
|->a|b->00110011->51
^->a^b->00110010


bitwise operators are basically , operations that you perform by sort of
combining/operating on each bit one by one




Given an array of N positive integers, compute the sum of XOR over all pairs:
more formally,
sum of (v[i] XOR v[j]) for all 1<=i<j<=N
we can solve the above problem bit by bit!

that is :


the answer to our question would be:

2^0 * (answer of rightmost bit)+2^1*(answer of second rightmost bit)..........

we can consider each bit of the vector v

v0^v1+v0^v2.....vn-2^vn-1
so the trivial approach takes n*(n-1)/2 operations, which is too slow for our
liking



say v contained only 0's and 1's, then what would be our answer?

0 0 1 1 0 1 0 1

then the sum of v[i]^v[j] across all pairs->
so this is sum is basically the number of pairs such that i<j and v[i]!=v[j]

count of ones *count of zeros

*/
int solve_subproblem(vector<int> v, int n) {
  int zeroes = 0, ones = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] == 0) {
      zeroes++;
    } else {
      ones++;
    }
  }
  return zeroes * ones;
}
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ans = 0;
  for (int bit = 0; bit < 32; bit++) {
    // here we solve the subproblem on the bit'th bit from the right
    vector<int> binary_v;
    for (int i = 0; i < n; i++) {
      binary_v.push_back(v[i] % 2);
      v[i] = (v[i] / 2);
    }
    // binary_v contains the equivalent list of 0's and 1's if only the bit'th
    // bit was there
    // by shift, we mean, left shift-> add "bit" number of zeroes to the right
    // 2^bit is nothing but 1000000
    int weight_ans = (1ll << bit);
    ans += (weight_ans * solve_subproblem(binary_v, n));
  }
  // so number of operations used is about 32*n , which is 32*2*10^5 which is
  // less than 1e8
  cout << ans << endl;
  return 0;
}