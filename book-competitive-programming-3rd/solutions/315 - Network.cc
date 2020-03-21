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

static int n;
static vii g[102];

// If a root has more than one child, it is an articulation vertex.
static int dfsNumCnt, rootChildren, dfsRoot;

// parent is for finding back edge which is not a direct edge to its parent.
static vi dfs_parent, dfs_num, dfs_low;

static vector<bool> is_articulation_vertex;

static void sol(const int u) {
  dfs_low[u] = dfs_num[u] = dfsNumCnt++;
  for(auto &v : g[u]) {
    if(dfs_num[v.first] == -1) {
      dfs_parent[v.first] = u;
      if(u == dfsRoot) rootChildren++;

      sol(v.first);

      if(dfs_low[v.first] >= dfs_num[u])
        is_articulation_vertex[u] = true;

      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    } else if (v.first != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
  }
}

static int sol() {
  repi(i, n) {
    if(dfs_num[i] == -1) {
      dfsRoot = i; rootChildren = 0;
      sol(i);
      is_articulation_vertex[dfsRoot] = (rootChildren > 1);
    }
  }

  int cnt = 0;
  for(auto i : is_articulation_vertex)
    cnt += i;

  return cnt;
}

int main(void)
{
  string s;
  while(getline(cin, s), s[0] != '0') {
    sscanf(s.c_str(), "%d", &n);
    repi(i, n)
      g[i].clear();
    dfs_parent.assign(n, -1);
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    is_articulation_vertex.assign(n, false);

    dfsNumCnt = rootChildren = 0;

    while(getline(cin, s), s[0] != '0') {
      stringstream ss(s);
      int u,v;
      ss >> u; u--;
      while(ss>>v) {
        v--;
        g[u].pb(mp(v, 0));
        g[v].pb(mp(u, 0));
      }
    }
    /* trace1(n);
     * repi(i, n) {
     *   for(auto &p : g[i]) {
     *     trace3(i, p.first, p.second);
     *   }
     * } */
    printf("%d\n", sol());
  }
  
  return 0;
}
