#include <bits/stdc++.h>

using namespace std;

int main(void)
{
  int n, m;

  while(cin >> n >> m, !cin.eof()) {
    unordered_map<int, vector<int> > g; // <value, indices>

    for(int i = 0; i < n; i++) {
      int temp; cin >> temp;

      if(g.find(temp) == g.end()) {
        vector<int> v;
        g[temp] = v;
      }

      g[temp].push_back(i+1);
    }

    for(int i = 0; i < m; i++) {
      int nth, value; cin >> nth >> value;

      if(g.find(value) != g.end()
          && nth <= g[value].size()) {
        cout << g[value][nth-1];
      } else {
        cout << 0;
      }
      cout << endl;
    }

  }
  
  return 0;
}
