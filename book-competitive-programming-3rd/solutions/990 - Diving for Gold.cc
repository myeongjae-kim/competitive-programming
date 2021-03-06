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

static int t, w, n, d[31], v[31], rt[31], memo[31][1003];
bool get_gold[31][1003];

int sol(const int idx, const int time) {
  if(time < 0) {
    return INT_MIN;
  }
      
  if(idx == n) {
    return 0;
  }

  if(memo[idx][time] != -1)
    return memo[idx][time];

  int ans1 = sol(idx+1, time);
  int ans2 = v[idx] + sol(idx+1, time - rt[idx]);

  // for tracing
  if(ans2 > ans1)
    get_gold[idx][time] = true;

  return memo[idx][time] = max(ans1, ans2);
}

vi find_path(int idx, int time) {
  vi ans;

  while(idx < n && time > 0) {
    if(get_gold[idx][time] == true) {
      ans.pb(idx);
      time -= rt[idx];
    }
    idx++;
  }

  return ans;
}

int main(void)
{
  bool is_first = true;
  while(scanf("%d %d", &t, &w) != EOF) {
    sd(n);
    repi(i,n) {
      scanf("%d %d", d+i, v+i);
      rt[i] = d[i] * 3 * w; // array rt(required time) is total times to get each gold.
    }

    SET(memo, -1);
    SET(get_gold, 0);

    if(is_first) is_first = false;
    else putchar('\n');

    printf("%d\n", sol(0, t));

    vi && way = find_path(0, t);

    printf("%d\n", SZ(way));
    for(auto i : way) {
      printf("%d %d\n", d[i], v[i]);
    }
  }

  return 0;
}
