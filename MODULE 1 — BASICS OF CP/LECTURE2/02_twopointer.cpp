#include <bits/stdc++.h>
using namespace std;
/*
subarray is just a contiguous set of indices in an array.
Given an array of positive integers and a target value X, find the length of the
longest contiguous subarray whose sum does not exceed X.
*/
int main() {
  // for each starting index of a subarray
  // try pushing the right index until we exceed the target sum

  // i, (i,i+1,i+2..n-1)-> n-i operations , n^2-> 10^10

  // instead of resetting the right index each time, we maintain right index as
  // the rightmost index such that the sum does not exceed X

  int n, X;
  cin >> n >> X;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];

  int current_sum = 0, r = 0;

  // instead of having l and r as the exact bounds,
  // we can have l as the left bound
  // and we can have r to signify one place after the right bound

  // we can easily check if window is empty by checking l==r
  // say v[0] itself is more than X?
  // l=0,r=0
  // l=1,r=0
  int max_length = 0;
  for (int l = 0; l < n; l++) {
    r = max(l, r);
    // try adding v[r] to our window and check if current sum is not exceeded
    while (r < n && (current_sum + v[r] <= X)) {
      current_sum += v[r];
      r++;
    }
    // we have the r as the rightmost index in the array such that sum of values
    // from l to r is <=X'
    max_length = max(max_length, r - l);
    if (r > l)
      current_sum -= v[l];
  }
  cout << max_length << endl; // this is our answer!
  return 0;
}