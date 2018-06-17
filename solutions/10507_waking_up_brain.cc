#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int g[26][26];
int waken_up[26];

int main(void)
{
  int n, e;

  while(cin >> n >> e, !cin.eof()) {

    memset(g, 0, sizeof(g));
    memset(waken_up, 0, sizeof(waken_up));

    string s; cin >> s;
    string init = s;

    int n_wakenup = 3;

    for(int i = 0; i < e; i++) {
      cin >> s;

      g[s[0]-'A'][s[1]-'A'] = 1;
      g[s[1]-'A'][s[0]-'A'] = 1;
    }

    if(n == 3) {
      cout << "WAKE UP IN, 0, YEARS" << endl;
      continue;
    }

    vector<int> already;
    already.push_back(init[0]-'A');
    already.push_back(init[1]-'A');
    already.push_back(init[2]-'A');

    waken_up[init[0]-'A'] = 3;
    waken_up[init[1]-'A'] = 3;
    waken_up[init[2]-'A'] = 3;

    int passed_years = 0;

    bool fail = false;
    while(n_wakenup < n) {
      if(already.empty()) {
        fail = true;
        break;
      }
      vi news;

      for(auto c : already) {
        for(int i = 0; i < 26; i++) {
          if(g[c][i] == 1) {
            waken_up[i]++;
            if(waken_up[i] == 3) {
              news.push_back(i);
            }
          }
        }
      }

      n_wakenup += news.size();
      already = news;
      passed_years++;
    }

    if(fail) {
      cout << "THIS BRAIN NEVER WAKES UP" << endl;
    } else {
      cout << "WAKE UP IN, " << passed_years << ", YEARS" << endl;
    }
  }
  
  return 0;
}
