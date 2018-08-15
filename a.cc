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


/* Note.
 *
 * Don't do memo while calculating the answer
 * e.g.) return max(memo[item+1][rem] = sol(item+1, rem),
 *                  memo[item+1][rem - w[item]] = sol(item+1, rem - w[item]));
 * 
 * Also, memo current arguments. Do not touch memo of next arguments.*/

int n;
int p[1003];
int w[1003];
int g;
int mw[102];
int memo[1003][31];

int sol(const int item, const int rem) {
  if(rem == 0 || item == n) return 0;
  if(memo[item][rem] != -1) return memo[item][rem];
  if(w[item] > rem) return memo[item][rem] = sol(item+1, rem);
  return memo[item][rem] = max(sol(item+1, rem),
                                  p[item] + sol(item + 1, rem - w[item]));
}

int main(void) {
  int TC; sd(TC);

  while(TC--) {
    sd(n);
    SET(memo, -1);
    repi(i, n) {
      sd(p[i]); sd(w[i]);
    }
    sd(g);
    repi(i, g) {
      sd(mw[i]);
    }

    int ans = 0;
    repi(i, g) {
      ans += sol(0, mw[i]);
    }

    printf("%d\n", ans);
  }

  return 0;
}
