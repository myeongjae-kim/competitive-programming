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

int n, m;
vector<int> C;

bool sol(int m, int c) {
  int sum = 0;
  repi(i, n) {
    // container is too small
    if(C[i] > c)
      return false;

    sum += C[i];
    if(sum > c) {
      m--;
      sum = C[i];
    }

    // No more containers
    if(m <= 0)
      return false;
  }

  return true;
}

int main(void)
{
  while(scanf("%d", &n) != EOF) {
    int ibuf;
    scanf("%d", &m);

    C.clear();
    
    repi(i,n) {
      scanf("%d", &ibuf);
      C.pb(ibuf);
    }

    // container's maximum is 1e9
    int min = 1, max = 1000000000;
    int mid, c;

    // We must iterate while loop when min == max.
    while(min <= max) {
      mid = (min + max) / 2;

      if(sol(m, mid)) {
        c = mid;

        // We know that mid is acceptable,
        // so max = mid - 1 for preventing duplicated calculation
        max = mid - 1;
      } else {

        // We know that mid is unacceptable,
        // so min = mid + 1 for preventing duplicated calculation
        min = mid + 1;
      }
    }

    printf("%d\n", c);
  }

  return 0;
}
