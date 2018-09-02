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

enum color {UNDEF, RED, BLACK};
static enum color c[202];

static bool is_bicolorable(int u, enum color clr) {
  c[u] = clr;

  for(auto i : g[u]) {
    if(c[i] == c[u])
      return false;
    else if(c[i] == UNDEF)
      if(is_bicolorable(i, clr == RED ? BLACK : RED) == false)
        return false;
  }

  return true;
}

static bool is_bicolorable() {
  return is_bicolorable(0, RED);
}

int main(void)
{
  while(sd(n), n) {
    int edges; sd(edges);

    repi(i, n) {
      g[i].clear();
    }
    memset(c, UNDEF, sizeof(enum color) * n);

    repi(i, edges) {
      int u, v;
      sd(u), sd(v);

      g[u].pb(v);
      g[v].pb(u);
    }
    
    if(!is_bicolorable())
      printf("NOT ");
    printf("BICOLORABLE.\n");


  }
  
  return 0;
}
