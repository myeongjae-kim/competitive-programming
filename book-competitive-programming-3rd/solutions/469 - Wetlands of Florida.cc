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

// Notoriously tricky to get inputs!

#define MAX_N 100

static int R, C;
static string v[MAX_N];
static vector< vector<bool> > vis;

int dp[MAX_N][MAX_N];

static int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
static int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

static int sol(const int r, const int c) {
  if(!(0 <= r && r < R && 0 <= c && c < C)
      || vis[r][c] || v[r][c] == 'L')
    return 0;

  vis[r][c] = true;

  // assert(v[r][c] == 'W');
  int cnt = 0;

  repi(i, 8) {
    cnt += sol(r+dr[i], c+dc[i]);
  }

  return cnt + 1;
}

static void print_map() {
  repi(i, R) {
    cout << v[i] << endl;
  }
}

static void memo_answer(const int r, const int c, const int ans) {
  if(!(0 <= r && r < R && 0 <= c && c < C)
      || v[r][c] == 'L' || !vis[r][c])
    return;

  // It's okay to turn off flag because of dp array.
  // Already visited water cell cannot be revisited because of the dp array.
  vis[r][c] = false;

  dp[r][c] = ans;
  repi(i, 8) {
    memo_answer(r+dr[i], c+dc[i], ans);
  }
}

int main(void)
{
  string s;
  getline(cin, s); // remove line break
  getline(cin, s); // remove empty line
  DRT() {
    R = 0;
    repi(i, MAX_N) {
      getline(cin, s);
      if( !(s[0] == 'L' || s[0] == 'W') ) break;

      v[i] = s;
      R++;
    }
    C = v[0].length();

    // trace2(R, C);
    // print_map();

    vis.assign(MAX_N, vector<bool>(MAX_N, false));
    SET(dp, 0);

    while(!cin.eof() && (s != "")) {
      int r, c, ans;
      sscanf(s.c_str(), "%d %d", &r, &c);
      r--; c--;

      if(dp[r][c] == 0) {
        ans = sol(r, c);
        memo_answer(r, c, ans);
      } else {
        ans = dp[r][c];
      }
      printf("%d\n", ans);

      getline(cin, s);
    }

    if(t) puts("");
  }

  return 0;
}
