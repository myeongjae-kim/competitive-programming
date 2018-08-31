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

static int R,C,M,N, even, odd;

static int mr[8], mc[8]; // move row, move col;

static bool water[102][102];
static bool visited[102][102];

static void sol(const int r, const int c) {
  if( !(0 <= r && r < R && 0 <= c && c < C)
      || visited[r][c] || water[r][c])
    return;

  visited[r][c] = true;

  int cnt = 0;
  //count movable lands
  map<int, bool> counted;

  repi(i, 8) {
    int nr, nc;
    nr = r + mr[i];
    nc = c + mc[i];
  
    if( (0 <= nr && nr < R && 0 <= nc && nc < C)
        && water[nr][nc] == false
        && counted[nr * 100 + nc] == false) {
      cnt++;
      counted[nr * 100 + nc] = true;
      sol(nr, nc);
    }
  }

  if(cnt & 1) odd++;
  else even++;

  // printf("%s: %d, %d\n",(cnt&1) ? "odd" : "eve", r, c);
}

int main(void)
{
  int TC; sd(TC);

  for(int tc = 1; tc <= TC; tc++) {
    even = odd = 0;
    sd(R); sd(C); sd(M); sd(N);
    SET(water, 0);
    SET(visited, 0);

    mr[0] = M; mc[0] = N;
    mr[1] = M; mc[1] = -N;
    mr[2] = -M; mc[2] = N;
    mr[3] = -M; mc[3] = -N;
    mr[4] = N; mc[4] = M;
    mr[5] = N; mc[5] = -M;
    mr[6] = -N; mc[6] = M;
    mr[7] = -N; mc[7] = -M;

    DRT() {
      int r, c; sd(r); sd(c);
      water[r][c] = true;
    }

    sol(0,0);
  
    printf("Case %d: %d %d\n", tc, even, odd);
  }
  
  return 0;
}

