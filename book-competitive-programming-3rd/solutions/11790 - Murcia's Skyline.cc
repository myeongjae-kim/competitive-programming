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

int n;
vi h, w, lis, lds;

int main(void)
{
  int TC; sd(TC);
  for (int tc = 1; tc <= TC; ++tc) {
    sd(n);
    h.clear(); w.clear(); lis.clear(); lds.clear();
    h.resize(n); w.resize(n); lis.resize(n); lds.resize(n);

    repi(i, n) 
      sd(h[i]);
    
    repi(i, n) 
      sd(w[i]);

    // lis
    int lis_max = 0;
    lis[0] = w[0];
    lis_max = max(lis[0], lis_max);
    for(int i = 1; i < n; i++) {
      int ibuf = 0;
      for(int k = 0; k < i; k++) {
        if(h[k] < h[i]) {
          ibuf = max(ibuf, lis[k]);
        }
      }
      lis[i] = ibuf + w[i];
      lis_max = max(lis[i], lis_max);
    }

    // lds
    int lds_max = 0;
    lds[0] = w[0];
    lds_max = max(lds[0], lds_max);
    for(int i = 1; i < n; i++) {
      int ibuf = 0;
      for(int k = 0; k < i; k++) {
        if(h[k] > h[i]) {
          ibuf = max(ibuf, lds[k]);
        }
      }
      lds[i] = ibuf + w[i];
      lds_max = max(lds[i], lds_max);
    }

    printf("Case %d. ", tc);
    if(lis_max >= lds_max) {
      printf("Increasing (%d). Decreasing (%d).\n", lis_max, lds_max);
    } else {
      printf("Decreasing (%d). Increasing (%d).\n", lds_max, lis_max);
    }
  }
  
  return 0;
}
