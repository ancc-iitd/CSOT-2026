#include <bits/stdc++.h>
using namespace std;
int main() {
  map<int, int> m;
  // map is a list of key,value pairs.
  m[5] = 10;
  m[3] = 20;
  m[4] = 20;
  vector<int> v = {1, 3, 5, 6, 7, 10};

  for (int x : v) {
    m[x]++;
  }

  cout << m[2] << endl; // returns the number of times 2 appears in the vector,
                        // which is 0

  // m[x] costs us logn operations where n is the size of the map.

  for (pair<int, int> p : m) {
    cout << p.first << " " << p.second << endl;
  }

  auto it = m.begin(); // maps ordered by their key in ascending order

  cout << (*it).first << " " << (*it).second << endl; // 3 21

  m.lower_bound(4); // returns an iterator corresponding to the first key in m
                    // which is >=4

  m.upper_bound(4); // returns an iterator corresponding to the first key in m
                    // which is >4

  map<int, int>::iterator it1 = m.begin();
  while (it1 != m.end()) {
    cout << (*it1).first << " " << (*it1).second << endl;
    it1++;
  }

  // say i want 4th element of the map, then i cant do it by just doing mp[4]
  return 0;
}