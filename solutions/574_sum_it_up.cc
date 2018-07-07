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

int n, t;

vi arr;
vector< vi > ans;

void sol(vi & v, int idx, int sum) {
  // base case
  if(sum == t) {
    ans.pb(v);
    return;
  } else if(sum > t || idx == n) {
    return;
  }

  for(int i = idx; i < n; i++) {
    v.pb(arr[i]);
    sol(v, i+1, sum + arr[i]);
    v.pop_back();
  }

}

void sol() {
  vi v;
  v.reserve(12);

  for(int i = 0; i < n; i++) {
    v.pb(arr[i]);
    sol(v, i+1, arr[i]);
    v.pop_back();
  }
}

void print(vi & v) {
  printf("%d", v[0]);
  for(size_t i = 1; i < v.size(); i++) {
    printf("+%d", v[i]);
  }
  putchar('\n');
}

int main(void)
{
  arr.reserve(12);
  ans.reserve(100);
  while(scanf("%d %d", &t, &n), t || n) {
    arr.clear();
    ans.clear();

    for(int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      arr.pb(temp);
    }

    sol();

    printf("Sums of %d:\n", t);
    if(ans.empty()) {
      printf("NONE\n");
      continue;
    }

    sort(ans.begin(), ans.end());

    print(ans.back());
    for(int i = ans.size() - 2; i >= 0; i--) {
      if(ans[i+1] != ans[i]) {
        print(ans[i]);
      }
    }
  }
  
  return 0;
}
