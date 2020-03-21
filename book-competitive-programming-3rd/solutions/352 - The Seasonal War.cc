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

// 'Adjacent vertices' include diagonal sides.
#define MAX_N 30

static int n;
static vector< vector<bool> > v;
static vector< vector<bool> > visited; 

static const int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
static const int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

static void visit_eagle(const int r, const int c) {
  if(!(0 <= r && r < n && 0 <= c && c < n)
      || visited[r][c] || !v[r][c])
    return;

  visited[r][c] = true;
  
  repi(i, 8) {
    visit_eagle(r+dr[i], c+dc[i]);
  }
}

static int sol() {
  int cnt = 0;

  repi(i, n) {
    repi(k, n) {
      if(v[i][k] && !visited[i][k]) {
        visit_eagle(i, k);
        cnt++;
      }
    }
  }

  return cnt;
}

int main(void)
{
  int tc = 1;
  string s;

  v.assign(MAX_N, vector<bool>(MAX_N, false));

  while(sd(n) != EOF) {
    getline(cin, s); //remove line break

    repi(i, n) {
      getline(cin, s);
      repi(k, n) {
        v[i][k] = (s[k] == '1');
      }
    }

    visited.assign(MAX_N, vector<bool>(MAX_N, false));
    printf("Image number %d contains %d war eagles.\n", tc, sol());
  
    tc++;
  }
  return 0;
}
