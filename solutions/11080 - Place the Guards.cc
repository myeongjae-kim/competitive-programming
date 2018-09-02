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

//ios::sync_with_stdio(0); cin.tie(0);
// Use static and const for every function.

static int n;
static vector<int> g[202];
static vector<int> c;

static int sol(const int u) {
  if(g[u].empty())
    return 1;

  if(c[u] != INT_MAX)
    return 0;

  bool is_bipartite = true;
  int clr0 = 0, clr1 = 0;

  queue<int> q;
  q.push(u);

  c[u] = 0;
  clr0++;

  while(!q.empty() && is_bipartite) {
    int v = q.front();
    q.pop();

    for(auto i : g[v]) {
      if(c[i] == INT_MAX) {
        c[i] = 1-c[v];

        if(c[i] == 0) clr0++;
        else clr1++;

        q.push(i);
      } else if (c[i] == c[v]) {
        is_bipartite = false;
        break;
      }
    }
  }

  if(is_bipartite)
    return min(clr0, clr1);
  else
    return -1;
}

static int sol() {
  int sum = 0, ans;
  repi(i, n)
    if((ans = sol(i)) == -1)
      return -1;
    else
      sum += ans;

  return sum;
}

int main(void)
{
  DRT() {
    int e;
    sd(n), sd(e);
    repi(i,n)
      g[i].clear();
    c.assign(n, INT_MAX);

    repi(i, e) {
      int u,v; sd(u), sd(v);
      g[u].pb(v);
      g[v].pb(u);
    }

    printf("%d\n", sol());
  }

  return 0;
}
