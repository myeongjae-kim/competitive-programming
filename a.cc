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

double p,q,r,s,t,u;

double func(double x) {
  return p * (1.0 / exp(x)) + q * sin(x) + r * cos(x) + s * tan(x)
        + t * x*x;
}

int main(void)
{
  while(scanf("%lf", &p) != EOF) {
    scanf("%lf", &q);
    scanf("%lf", &r);
    scanf("%lf", &s);
    scanf("%lf", &t);
    scanf("%lf", &u);

    double lo, hi, x, result;
    lo = 0.0; hi = 1.0;

    if(abs(func(lo) + u) < 0.00001) {
      printf("%.4lf\n", lo);
      continue;
    }
    if(abs(func(hi) + u) < 0.00001) {
      printf("%.4lf\n", hi);
      continue;
    }

    while(true){
      x = (lo + hi) / 2;

      if(x < 0.00001 || x > 0.99999) {
        printf("No solution\n");
        goto next;
      }
      result = func(x);

      if(abs(result + u) < 0.00001) break;

      if(result + u > 0) { 
        // result is big. decrease result, or increase x.
        lo = x;
      } else {
        hi = x;
      }
    }
    printf("%.4lf\n", x);
next:;
  }
  return 0;
}
