#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>
#include <cstdint>

using namespace std;

typedef vector<int> vi;

enum status {NONE, UNVISITED, VISITING, VISITED};
enum kind {GRAPH, TREE, ACORN};

enum kind dfs(vector< vi > &g, vector<enum status>& status,
    int start, int depth, int &num_v) { // depth start at 1
  num_v--;
  status[start] = VISITING;

  enum kind result = TREE;

  bool is_acorn = true;

  for(auto next : g[start]) {
    if(status[next] == UNVISITED) {
      is_acorn = false;
      result = dfs(g, status, next, depth + 1, num_v);
    } else if (status[next] == VISITING) {
      // do nothing
    } else if( status[next] == VISITED) {
      result = GRAPH;
    } else {
      assert(false);
    }
  }

  status[start] = VISITED;

  if(result == GRAPH) {
    return result;
  } else {
    return (depth == 1 && is_acorn) ? ACORN : TREE;
  }
}



int main(void)
{
  int t; cin >> t;

  string s;
  getline(cin, s); // remove \n
  while(t--) {
    vector< vi > g(26);
    // read edge

    while(getline(cin, s), s[0] == '(') {
      int from, to;
      from = s[1]-'A'; to = s[3]-'A';
      g[from].push_back(to);
      g[to].push_back(from);
    }

    // read asterisk, skip
    assert(s[0]=='*');

    // read vertices
    getline(cin, s);
    vector<enum status> status(26);
    int num_v = 0;
    for(int i = 0; i < (int)s.length(); i += 2) {
      status[s[i]-'A'] = UNVISITED;
      num_v++;
    }

    // print output
    int tree = 0, acorn = 0;

    while(num_v) {
      for(int i = 0; i < 26; i++) {
        if(status[i] == UNVISITED) {
          enum kind result = dfs(g, status,i,1, num_v);

          if(result == TREE) {
            tree++;
          } else if (result == ACORN) {
            acorn++;
          }
        }
      }
    }

    cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s)." << endl;

    // goto next
  }

  return 0;
}
