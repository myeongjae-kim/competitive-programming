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
#include <stdio.h>

int M, C;
int K[22];
int g[22][22];
bool dp[2][202];

int main(void) {
  int TC; sd(TC);

  while(TC--) {
    int ans;
    SET(K, 0); SET(g, 0); SET(dp, false);

    sd(M); sd(C);
    repi(i, C) {
      sd(K[i]);
      repi(k, K[i]) {
        sd(g[i][k]);
      }
    }

    // base case
    repi(k, K[0]) {
      if(M - g[0][k] >= 0)
        dp[0][M-g[0][k]] = true;
    }

    for (int i = 1; i < C; ++i) {
      SET(dp[i&1], false);
      repi(m, M) {
        if(dp[!(i&1)][m] == true) {
          repi(k, K[i]) {
            if(m - g[i][k] >= 0) {
              dp[i&1][m-g[i][k]] = true;
            }
          }
        }
      }
    }

    for(ans = 0; ans < M && dp[!(C&1)][ans] == false; ans++);

    if(ans == M)
      printf("no solution\n");
    else
      printf("%d\n", M-ans);
  }

  return 0;
}
