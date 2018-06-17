#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int find(vi & set, int i) {
  if(i == set[i])
    return i;

  return set[i] = find(set, set[i]);
}

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);
  int t; cin >> t;

  string s;
  getline(cin, s); // remove \n

  while(t--) {
    int n; cin >> n;
    vi set(n+1), rank(n+1);

    for (int i = 0; i < n+1; ++i) {
      set[i] = i;
    }

    int ans1 = 0, ans2 = 0;

    getline(cin, s); // remove \n
    while(getline(cin, s), s.length()) {
      char cmd; int c1, c2;
      int s1, s2;

      stringstream ss(s);
      ss >> cmd >> c1 >> c2;

      switch(cmd) {
        case 'c':
          s1 = find(set, c1);
          s2 = find(set, c2);
          if(rank[s1] > rank[s2]) {
            set[s2] = set[s1];
          } else {
            set[s1] = set[s2];
          }

          if(rank[s1] == rank[s2]) {
            rank[s2]++;
          }

          break;

        case 'q': 
          if(find(set, c1) == find(set, c2)) {
            ans1++;
          } else {
            ans2++;
          }
          break;

        default:
          assert(false);
      }
    }
    cout << ans1 << ',' << ans2 << endl;
    if(t != 0) {
      cout << endl;
    }
  }

  return 0;
}
