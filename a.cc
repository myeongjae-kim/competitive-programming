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

static int N, M;

static string input[102];
static unordered_map<string, int> m;

static vector<int> g[102];
static int indegree[102];

static vector<int> ans;
static vector<bool> visited;

void sol() {
  // In the case there is no relation between two beverages
  // Dilbert should start drinking the one that appears first in the input.
  priority_queue<int, vector<int>, greater<int> > q;

  repi(i, N) {
    if(indegree[i] == 0) {
      q.push(i);
    }
  }

  while(!q.empty()) {
    int i = q.top();
    q.pop();

    ans.pb(i);

    for(auto k : g[i]) {
      indegree[k]--;

      if(indegree[k] == 0)
        q.push(k);
    }
  }

}

int main(void)
{
  string s, u, v;
  int TC = 1;

  while(sd(N) != EOF) {
    getline(cin, s); // remove line break;

    repi(i, N) {
      getline(cin, input[i]);
      m[input[i]] = i;

      g[i].clear();
    }

    sd(M);
    getline(cin, s); // remove line break;

    SET(indegree, 0);
    repi(i, M) {
      getline(cin, s);
      int idx = s.find(" ");
      u = s.substr(0, idx);
      v = s.substr(idx+1);

      g[m[u]].pb(m[v]);
      indegree[m[v]]++;
    }

    ans.clear();
    visited.assign(N, false);
    sol();

    cout << "Case #" << TC++ <<": Dilbert should drink beverages in this order: ";

    auto it = ans.begin();
    cout << input[*it];
    for(it++; it != ans.end(); it++) {
      cout << ' ' << input[*it];
    }
    cout << "." << endl << endl;
  }

  return 0;
}
