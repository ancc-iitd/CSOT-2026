#include <bits/stdc++.h>
using namespace std;
/*
problem:
You are given n activities with their start and end times. Your task is to
select the maximum number of activities that can be performed by a single
person, assuming that a person can only work on a single activity at a time.

idea1:
oh shorter activities always better.
[           ]
           [   ]
              [              ]

idea2:
events that make me wait less are better
solves the above testcase by greedily choosing the activity that begins
earliest.
[         ]
            [                                  ]
                [  ] [  ] [ ]

idea3:
events that end first are best
start at t=0,
pick the event with starting time greater than 0, and minimum ending time (say
t1)

pick the event with the staring time greater than t1, and minimum ending
time(say t2)

...


...
*/
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> times(n);
  for (int i = 0; i < n; i++) {
    cin >> times[i].second >> times[i].first;
  }
  sort(times.begin(), times.end());
  // we have events sorted by end time
  int current_time = 0;
  int events_attended = 0;
  for (int i = 0; i < n; i++) {
    // check , does times[i] have a starting time more than the current time?
    // yes-> we sit through this event
    // no-> skip this event.
    if (times[i].second >= current_time) {
      // can attend.
      events_attended++;
      current_time = times[i].first;
    } else {
      // skip
    }
  }
  cout << events_attended << endl;
  return 0;
}