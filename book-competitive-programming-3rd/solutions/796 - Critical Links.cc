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

static int n, dfsNumCnt;
static vector< vii > g;

static vi dfs_num, dfs_low, dfs_parent;
static vii ans;

static void sol(const int u) {
  dfs_num[u] = dfs_low[u] = dfsNumCnt++;
  for(auto &v : g[u]) {
    if(dfs_num[v.first] == -1) {
      dfs_parent[v.first] = u;

      sol(v.first);

      if(dfs_low[v.first] > dfs_num[u]) {
        int from, to;
        from = min(v.first, u);
        to = max(v.first, u);
        ans.pb(mp(from, to));
      }
    
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
    } else if (v.first != dfs_parent[u]) {
      dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
    }
  }
}

static void sol() {
  repi(i, n) {
    if(dfs_num[i] == -1) {
      sol(i);
    }
  }

  sort(all(ans));

  /* repi(i, n) {
   *   trace3(i, dfs_num[i], dfs_low[i]);
   * } */
}

int main(void)
{
  string s, s1, s2;
  while (getline(cin, s)) {
    if(s == "") continue;

    sscanf(s.c_str(), "%d", &n);

    g.assign(n, vii(0));
    dfs_num.assign(n, -1);
    dfs_low.assign(n, -1);
    dfs_parent.assign(n, -1);
    dfsNumCnt = 0;
    ans.clear();

    repi(i, n) {
      getline(cin, s);
      // find ')'
      int k;
      for(k = 0; k < SZ(s) && s[k] != ')'; k++);
      k++;

      if(k == SZ(s))
        continue;

      s1 = s.substr(0, k);
      s2 = s.substr(k+1);
      /* trace2(s1, s2); */

      int u, v;
      sscanf(s1.c_str(), "%d (%d)", &u, &k);

      stringstream ss2(s2);
      repi(l, k) {
        ss2 >> v;
        g[u].pb(mp(v,0));
        g[v].pb(mp(u,0));
      }
    }

    /* repi(i, n) {
     *   for(auto &p : g[i]) {
     *     trace3(i, p.first, p.second);
     *   }
     * } */

    sol();

    printf("%d critical links\n", SZ(ans));
    for(auto &p : ans) {
      printf("%d - %d\n", p.first, p.second);
    }
    puts("");
  }
  
  return 0;
}

