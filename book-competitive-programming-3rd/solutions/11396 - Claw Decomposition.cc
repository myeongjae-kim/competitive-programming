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
static vector<int> g[302];
static int c[302];

static bool sol(const int i) {
  queue<int> q;
  q.push(i);
  c[i] = 0;

  while(!q.empty()) {
    int u;
    u = q.front(); q.pop();

    for(auto v : g[u]) {
      if(c[u] == c[v])
        return false;
      else if (c[v] == -1) {
        c[v] = 1-c[u];
        q.push(v);
      }
    }
  }

  return true;
}

static bool sol() {
  repi(i, n) {
    if(c[i] == -1) {
      if(sol(i) == false)
        return false;
    }
  }

  return true;
}

int main(void)
{
  while(sd(n), n) {
    int u,v;

    repi(i, n)
      g[i].clear();

    SET(c, -1);

    while(sd(u), sd(v), u||v) {
      u--; v--;
      g[u].pb(v);
      g[v].pb(u);
    }
    printf("%s\n", sol() ? "YES" : "NO");
  }
  
  return 0;
}
