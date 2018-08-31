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

#define MAX_N 50004

static int g[MAX_N], v[MAX_N];

// Using set, unordered_set, map, unordered_map in a recursive function
// can make TLE!
//
// Set, unordered_set, and map make TLE in this problem. Only unordered_map
// gets AC. Using a boolean array is much more faster than STL structures.
//
// Array and vector does not have significant difference of speed, but
// array is slightly faster than vector.
//
// Using boolean array is faster than integer array.

// unordered_map<int, bool> visited;
static bool visited[MAX_N];
static int n;

static int sol(const int idx) {
  if(visited[idx] == true) {
    return v[idx] = 1;
  }

  visited[idx] = true;
  v[idx] = sol(g[idx]) + 1;

  // Turn off visited flag for other searches.
  // If you do not turn off this flag, the answer can be wrong.
  //
  // Redundant search is prevented by checking v[i] in sol(),
  // so do not worry about the spending time.

  visited[idx] = false;

  return v[idx];
}

static int sol() {
  // You have to do dfs from smaller index.
  // The problem wants smaller index when the number of sent email is same.

  // int max_idx = 1;
  for(int i = 1; i <= n; i++) {

    // You don't need to re-dfs when v[i] has a value.
    // It means that some other indices have a bigger value than idx i.
    if(v[i] != 0) {
      continue;
    }

    sol(i);

    // if(v[i] > v[max_idx])
    //   max_idx = i;
  }

  // Finding maximum index in another for loop is faster than
  // finding it in the loop above.
  int max_idx = 1;
  for(int i = 2; i <= n; i++) {
    if(v[i] > v[max_idx])
      max_idx = i;
  }

  return max_idx;
}


int main(void)
{
  int TC; sd(TC);
  for(int tc = 1; tc <= TC; tc++) {
    // Redundancy initialization of big size containers can make TLE!
    // visited.clear();
    // SET(g, 0);

    SET(v, 0);

    sd(n);
    repi(i, n) {
      int u,v;
      sd(u); sd(v);
      g[u] = v;
    }

    printf("Case %d: %d\n", tc, sol());
  }
  
  return 0;
}
