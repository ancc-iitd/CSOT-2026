#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2) {
  if (p1.first == p2.first)
    return p1.second > p2.second;
  return p1.first < p2.first;
}
int main() {
  vector<pair<int, int>> v1;
  // comp({3,4},{3,2})->true
  v1 = {{3, 4}, {3, 2}, {5, 6}};
  // s
  //  comp must return true if p1 should come before p2 in the sorted order
  sort(v1.begin(), v1.end(), comp);
  for (auto p : v1)
    cout << p.first << " " << p.second << endl;

  //{3,4},{3,2},{5,6}
  // sort by the first element, in case of tie, sort by the second element in
  // decreasing order

  // comp({3,4},{3,4})-> false

  //
  return 0;
}