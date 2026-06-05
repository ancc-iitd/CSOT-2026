#include <bits/stdc++.h>
using namespace std;
int main() {
  // stack has three main operations:
  // push,pop, top
  // LIFO PRINCIPLE
  string s = "[[{}}))]";
  // does each opening bracket have a closing bracket?
  // 1 3 5 7
  // pop would pop 1 and not 7 in a queue
  stack<char> st;
  queue<char> q;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '[' or s[i] == '(' or s[i] == '{') {
      st.push(s[i]);
    } else {
      map<char, char> m;
      m[']'] = '[';
      m[')'] = '(';
      m['}'] = '{';
      if (s[i] == '}' || s[i] == ')' || s[i] == ']') {
        if (!st.empty()) {
          if (st.top() == m[s[i]]) {
            st.pop();
            continue;
          } else {
            cout << "NO,we found a mismatch" << endl;
            return;
          }
        } else {
          cout << "THERE IS NO MATCHING bracket at all" << endl;
          return;
        }
      }
    }
  }
  if (!st.empty()) {
    cout << "NO,there are some opening brackets which do not have a closing "
            "bracket"
         << endl;
  } else {
    cout << "YES,all brackets have a matching closing bracket" << endl;
  }

  return 0;
}