#include <bits/stdc++.h>
using namespace std;
int main() {
  // set is a sorted collection of distinct elements

  set<int> s;
  s.insert(5);
  s.insert(3);
  s.insert(5);
  s.insert(1);

  // s would be {1,3,5}

  // s[0],s[1],s[2] does not work for sets

  for (int x : s)
    cout << x << " "; // 1 3 5

  auto it = s.begin();
  it++;
  cout << *it << endl; // 3
  it--;
  cout << *it << endl; // 1
  s.insert(4);
  // inserting in a set takes O(logn) operations, where n is the size of the set
  s.erase(3);

  s.erase(s.begin()); // erase the first element of the set, which is 1

  // lower and upper bound for sets
  auto it = s.lower_bound(4); // returns an iterator corresponding to the first
  // element in s which is >=4

  vector<int> v = {1, 3, 3, 5, 6, 7, 10};
  set<int> s1(v.begin(), v.end()); // s1 would be {1,3,5,6,7,10}
  // printing distinct numbers in the vector
  // 10^5 inserts, 10^6, 10^6 searches
  // 5th element
  auto it = s1.begin();
  for (int i = 0; i < 4; i++)
    it++;
  cout << *it << endl; // 6
  return 0;
}