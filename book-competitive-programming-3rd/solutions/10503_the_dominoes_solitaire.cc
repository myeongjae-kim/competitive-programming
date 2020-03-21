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

bool sol(pii & start, vector< pii > & v, pii & end,
          vector< pii > & input, int n, int hh) {
  // base case
  if((int)v.size() == n) {

    // 'start' and 'end' pieces cannot be flopped.
    // Only intermediate dominoes can be flopped.
    if(v.back().S == end.F) {
      return true;
    }
    return false;
  }

  // recursion
  for(int i = 0; i < (int)input.size(); i++) {
    if(hh & (1<<i))
      continue;

    auto p = input[i];

    // flop the intermediae dominoe
    for(int k = 0; k < 2; k++) {
      if(v.back().S == p.F) {
        v.push_back(p);
        hh |= (1 << i);
        
        if(sol(start, v, end, input, n, hh))
          return true;

        hh &= ~(1 << i);
        v.pop_back();
      }
      // flop the intermediae dominoe
      swap(p.F, p.S);
    }
  }
  return false;
}


bool sol(pii & start, pii & end, vector< pii > & input, int n) {
  vector< pii > v;
  int hh = 0;

  for(int i = 0; i < (int)input.size(); i++) {
    auto p = input[i];

    // flop the intermediae dominoe
    for(int k = 0; k < 2; k++) {
      if(start.S == p.F) {
        v.push_back(p);
        hh |= (1 << i);
        
        if(sol(start, v, end, input, n, hh))
          return true;

        hh &= ~(1 << i);
        v.pop_back();
      }
      // flop the intermediae dominoe
      swap(p.F, p.S);
    }
  }

  return false;
}



int main(void)
{
  int n, m;
  while(scanf("%d", &n), n) {
    scanf("%d", &m);

    pii start;
    pii end;
    vector< pii > v;

    scanf("%d %d", &start.F, &start.S);
    scanf("%d %d", &end.F, &end.S);

    for(int i = 0; i < m; i++) {
      int f, s;
      scanf("%d %d", &f, &s);
      v.push_back(mp(f, s));
    }

    // 'start' and 'end' pieces cannot be flopped.
    // Only intermediate dominoes can be flopped.
    printf("%s\n", sol(start, end, v, n) ? "YES" : "NO");
  }
  
  return 0;
}

