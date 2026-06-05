#include <bits/stdc++.h>
using namespace std;
int main() {

  // multiset also allows us to have repeated elements

  // set even if you add 2 multiple times , it gets stored only once
  // and if you erase even once, it gets deleted completely

  // {1,2,2,3,5,5,5,4,6}
  //
  // m.erase(m.find(2));
  multiset<int> m;
  m.insert(5);
  auto it = m.find(5);
  // m.end() if 5 does not exist in m
  // else it would be an iterator corresponding to the first 5 in m

  if (m.find(5) != m.end())
    m.erase(m.find(5)); // this would erase only one 5 from the multiset, and
                        // the other 5s would still be there

  m.erase(5); // this would erase all 5s from the multiset

  // O(logn) operations for insert and erase in multisets, where n is the size
  // of the multiset
  // so in a vector, inserting/erasing in the middle would involve 1e5
  // operations if 1e5 elements are there multiset would take O(logn) operations
  // to insert/erase an element,

  m.lower_bound(5); // returns an iterator corresponding to the first element in
                    // m which is >=5

  m.upper_bound(
      5); // returns an iterator corresponding to the first element in m
  return 0;
}