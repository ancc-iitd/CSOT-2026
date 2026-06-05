#include <bits/stdc++.h>
using namespace std;
int main() {
  int count = 0;
  int n = 100000;
  int v[n];
  for (int i = 0; i < n; i++)
    cin >> v[i];
  int target = 2006;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (v[i] + v[j] == target) {
        count++;
      }
    }
  }
  // i=0-> j=1, j=2....i=n-1 : n-1 times
  // i-1-> j=2,3....n-1: n-2 times
  // n-1+n-2+n-3...1=n*(n-1)/2
  cout << count << endl;
  // 10^8 atomic operations per second ,
}