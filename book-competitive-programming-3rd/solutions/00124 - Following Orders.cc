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
// Use static and const for every function.

#define ALPHA 30
#define MAX_N 22
static vector<int> g[ALPHA];
static int indegree[ALPHA];
static int n;
static int chars[MAX_N];
static int used[MAX_N];

static void sol(string &s, const int used_chars) {
  if(used_chars == n) {
    cout << s << endl;
    return;
  }

  repi(i, n) {
    if(used[i] == false && indegree[chars[i]] == 0) {
      used[i] = true;
      for(auto k : g[chars[i]]) {
        indegree[k]--;
      }
      s.pb(chars[i]+'a');

      sol(s, used_chars + 1);

      s.pop_back();
      for(auto k : g[chars[i]]) {
        indegree[k]++;
      }
      used[i] = false;
    }
  }
}

static void sol() {
  string s;
  sol(s, 0);
}

int main(void)
{
  string s;
  bool is_first = true;

  while(getline(cin, s)) {
    if(is_first) is_first = false;
    else cout << endl;

    SET(indegree, 0);
    repi(i, ALPHA) {
      g[i].clear();
    }

    n = 0;
    for(auto c : s) {
      if(isalpha(c)) {
        chars[n++] = c-'a';
      }
    }

    sort(chars, chars+n);

    getline(cin, s);

    for(int i = 2; i < SZ(s); i += 4) {
      g[s[i-2]-'a'].pb(s[i]-'a');
      indegree[s[i]-'a']++;
    }

    sol();
  }

  return 0;
}
