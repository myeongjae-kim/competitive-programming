#include <bits/stdc++.h>
#define assn(n,a,b) assert(n<=b and n>=a)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define sd(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define TRACE
using namespace std;
//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);
#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)
#endif
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pii > vii;
typedef vector<bool> vb;

//ios::sync_with_stdio(0); cin.tie(0);
// Use static and const for every function.

int n,m;
unordered_map<string, int> s_to_i;
vector<string> i_to_s;

vii g[30];
vi dfs_num, dfs_low, S;
vb visited;
int dfsCnt;

void sol(int u) {
  dfs_num[u] = dfs_low[u] = dfsCnt++;
  visited[u] = true;
  S.pb(u);
  for(auto &v : g[u]) {
    if(dfs_num[v.first] == -1) 
      sol(v.first);
    if(visited[v.first] == true)
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if(dfs_low[u] == dfs_num[u]) {
    bool is_first = true;

    while(1) {
      int i = S.back(); S.pop_back();
      visited[i] = false;

      if(is_first) is_first = false;
      else cout << ", ";

      cout << i_to_s[i];

      if(i == u)
        break;
    }

    cout << endl;
  }
}

int TC = 1;
void sol() {
  dfs_num.assign(n, -1);
  dfs_low.assign(n, -1);
  visited.assign(n, false);
  S.clear();
  dfsCnt = 0;

  if(TC != 1) cout << endl;
  printf("Calling circles for data set %d:\n", TC++);
  
  repi(i, n) {
    if(dfs_num[i] == -1)
      sol(i);
  }
}

int main(void)
{
  while(sd(n), sd(m), n||m) {
    int name_cnt = 0;
    int u = 0, v = 0;
    string s, s1, s2;
    s_to_i.clear();
    i_to_s.clear();
    repi(i, n)
      g[i].clear();


    getline(cin, s); // remove line break

    repi(i, m) {
      getline(cin, s);
      int space = s.find(" ");

      s1 = s.substr(0, space);
      s2 = s.substr(space+1);

      if(s_to_i.find(s1) == s_to_i.end()) {
        s_to_i[s1] = name_cnt++;
        i_to_s.pb(s1);
      }

      if(s_to_i.find(s2) == s_to_i.end()) {
        s_to_i[s2] = name_cnt++;
        i_to_s.pb(s2);
      }

      u = s_to_i[s1];
      v = s_to_i[s2];

      g[u].pb(mp(v, 0));
    }

    /* repi(i, n) {
     *   trace3(i, i_to_s[i], s_to_i[i_to_s[i]]);
     * } */

    sol();
  
  }
  return 0;
}
