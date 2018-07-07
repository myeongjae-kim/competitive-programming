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
int const p[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

bool is_prime(int a) {
  for(int i = 0; i < (int)(sizeof(p)/sizeof(*p)); i++) {
    if(a == p[i])
      return true;
  }
  return false;
}

void sol(vi & v, int m, int idx) {
  // base case
  if(idx == (int)v.size()) {
    if( ! is_prime(v.front() + v.back()))
      return;

    printf("%d", v[0]);
    for(unsigned int i = 1; i < v.size(); i++) {
      printf(" %d", v[i]);
    }
    putchar('\n');
    return;
  }

  // recursion
  for(int i = 2; i<= n; i++) {
    if((m & (1<<i)) == 0
        && is_prime(i + v[idx-1])) {
      m |= (1<<i);
      v[idx] = i;
      sol(v, m, idx+1);
      m &= ~(1<<i);
    }
  }
}

void sol(vi & v) {
  int m = 1 << 1;
  int idx = 1;
  v[0] = 1;

  for(int i = 2; i <= n; i++) {
    if(is_prime(1 + i)) {
      v[idx] = i;
      m |= (1<<i);
      sol(v, m, idx + 1);

      m &= ~(1<<i);
    }
  }
}

int main(void)
{
  int tc = 0;
  while(scanf("%d", &n) != EOF) {
    vi v;
    v.resize(n);

    tc++;

    if(tc != 1)
      putchar('\n');
    printf("Case %d:\n", tc);

    sol(v);
  }
  return 0;
}
