#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

static vector<char> v;

static vector<int> g[26];

static int indegree[26];
static int used[26];

static bool has_answer;

static void sol(string &s, const int n_str) {
  if(n_str == (int)v.size()) {
    cout << s[0];
    for(int i = 1; i < n_str; i++) {
      cout << ' ' << s[i];
    }
    cout << endl;
    has_answer = true;
    return;
  }

  for(auto c : v) {
    int i = c-'A';

    if(!used[i] && indegree[i] == 0) {
      used[i] = true;
      for(auto k : g[i]) {
        indegree[k]--;
      }

      s.push_back(c);
      sol(s, n_str + 1);
      s.pop_back();

      for(auto k : g[i]) {
        indegree[k]++;
      }
      used[i] = false;
    }
  }
}

int main(void)
{
  int TC; cin >> TC;
  string s;

  while(TC--) {
    v.clear();
    memset(indegree, 0, sizeof(indegree));
    has_answer = false;

    for(int i = 0; i < 26; i++) {
      g[i].clear();
    }

    while(getline(cin, s), s == "");
    for(auto c : s)
      if(isalpha(c))
        v.push_back(c);

    sort(v.begin(), v.end());

    getline(cin, s);
    for(int i = 2; i < (int)s.length(); i += 4) {
      int u = s[i-2]-'A',v = s[i]-'A';
      g[u].push_back(v);

      indegree[v]++;
    }

    s.clear();
    sol(s, 0);
    if(!has_answer) cout << "NO" << endl;

    if(TC) cout << endl;
  }

  return 0;
}
