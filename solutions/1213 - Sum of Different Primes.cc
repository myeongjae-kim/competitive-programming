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

vi primes;

void init() {
  primes.pb(2);
  primes.pb(3);
  for(int i = 5; i <= 1120; i += 2) {
    bool is_prime = true;
    for(auto k : primes) {
      if(k > (int)sqrt(i) + 1) break;

      if(i % k == 0){
        is_prime = false;
        break;
      }
    }
    if(is_prime) primes.pb(i);
  }
}

int memo[1200][16][200];

int sol(int n, int k, int idx) {
  if(memo[n][k][idx] != -1)
    return memo[n][k][idx];

  if(n == 0 && k == 0)
    return 1;

  if(n<0||k<=0||n<primes[idx]||idx==SZ(primes))
    return 0;

  return memo[n][k][idx] = sol(n,k,idx+1) + sol(n-primes[idx],k-1,idx+1);
}

int main(void)
{
  init();
  SET(memo, -1);

  int n, k;
  while(scanf("%d %d", &n, &k), n||k) {
    printf("%d\n", sol(n,k,0));
  }
  return 0;
}
