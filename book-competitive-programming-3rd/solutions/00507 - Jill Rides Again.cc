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

int ary[20004];
int dp[20004];
int from[20004];
int to[20004];

int main(void) {
  int TC; sd(TC);

  for(int tc = 1; tc <= TC; tc++){
    int n; sd(n);
    SET(dp, -1);
    SET(from, -1);
    SET(to, -1);

    n--;
    repi(i, n) {
      sd(ary[i]);
    }

    if(ary[0] >= 0) {
      dp[0] = ary[0];
      from[0] = 0;
      to[0] = 0;
    }

    for (int i = 1; i < n; ++i) {
      if(dp[i-1] >= 0) {
        dp[i] = ary[i] + dp[i-1];
        from[i] = from[i-1];
        to[i] = i;
      } else if(ary[i] >= 0) {
        // start new sum
        dp[i] = ary[i];
        from[i] = i;
        to[i] = i;
      }
    }

    int ans = -1, f, t;
    repi(i, n) {
      if(dp[i] > ans) {
        // When range sum is bigger than before
        ans = dp[i];
        f = from[i];
        t = to[i];
      } else if (dp[i] == ans
          && to[i] - from[i] > t - f) {
        // Range sum is same. Tie break.
        ans = dp[i];
        f = from[i];
        t = to[i];
      }
    }

    if(ans > -1) {
      printf("The nicest part of route %d is between stops %d and %d\n",
          tc, f + 1, t + 2);
    } else {
      printf("Route %d has no nice parts\n", tc);
    }
  }

  return 0;
}
