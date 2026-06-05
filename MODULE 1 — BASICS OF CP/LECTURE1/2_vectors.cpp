#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v2(10, 5); // create a vector having 10 numbers, with a default 5

  vector<int> v1;
  for (int i = 0; i < 10; i++)
    v1.push_back(5);

  // v1[0]

  // v1[0] ->1st element of the vector
  // v1[1]->2nd element

  for (int i = 0; i < 10; i++)
    cout << v1[i] << endl;

  // v1[10]
  // range based for loops
  for (int element : v1) {
    element *= 2;
    cout << element << endl;
  } // elements of v1 are not changed
  for (int &element : v1) {
    element *= 2;
    cout << element << endl;
  } // elements of v1 are changed

  // v1.size()

  v1.pop_back();
  vector<int>::iterator it = v1.begin();
  vector<string> v;
  // v1.end()->signfies one place after the end of vector
  while (it != v1.end()) {
    cout << *it << endl;
    it++;
  }
  // insert elements
  v1.insert(v1.begin(), 10);
  // 1ST->2ND
  // 2ND->3RD
  // 3rd
  v1.insert(v1.begin() + 2, 10);

  // 3 1 4 6 9
  vector<int> v1 = {3, 1, 4, 6, 9};
  // v1.sort()

  sort(v1.begin(), v1.end());

  for (int x : v1)
    cout << x << " "; // v1 in sorted order

  // easy to use
  // allows us to access any element in the array at any time quite cheaply
  // expensive to insert stuff in between

  // 1 3 5 6 9                  7

  // v1.insert(v1.begin()+4,7); in worst case this ends up using n operations
  // instead of just one

  // n -> 10^5 , 10^5 , 10^5*10^5-> exceed the timetable

  // pair,

  std::pair<int, string> heights;
  // abhinav height 6ft
  heights = {6, "abhinav"};

  cout << heights.first << " " << heights.second << endl;

  vector<pair<int, string>> v3;
  v3.push_back(heights);
  v3.push_back(heights);
  // v3[0].first, v3[0].second

  vector<pair<pair<int, int>, int>> v4;
}