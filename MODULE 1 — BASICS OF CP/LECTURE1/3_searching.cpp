#include <bits/stdc++.h>
using namespace std;
int main() {
  int count = 0;
  int n = 100000;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int target = 2006;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    // for (int j = i + 1; j < n; j++) {
    //   if (v[i] + v[j] == target) {
    //     count++;
    //   }
    // target 11
    // 1 3 5 5 5 6 7 10 v.end()
    // }
    // v1.end()
    // binary search in the range (i+1,n-1) to search for the target-v[i]
    // lower_bound->given starting and ending iterators, and x, returns an
    // iterator corresponding to the first number in v1 which is >=x
    auto begin_search = v.begin() + i + 1;
    auto end_search = v.end();
    int search_for = target - v[i];
    auto it = lower_bound(begin_search, end_search, search_for);
    // v1.end()
    if (it == v.end())
      continue;
    else {
      if (*it == search_for) {
        // we found a complement
        // count++;
      }
    }
    // above works for vectors of distinct elements, but what if we have
    // repeated elements? last element we are searching for would be the element
    // before the first element >search_for first element we are searching for
    // would be the element which lower bound returns
    auto it1 = upper_bound(begin_search, end_search, search_for);
    // this would be the first element greater than search for
    // first element greater than x is,
    if (it1 == v.end())
      count += v.end() - it;
    else
      count += it1 - it;
  }
  // count is the number of pairs i,j such that i<j and v[i]+v[j]=target

  // 10nlogn operations which is way below 1e8
  cout << count << endl;
}