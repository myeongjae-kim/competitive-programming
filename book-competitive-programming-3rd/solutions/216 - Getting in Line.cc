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

static int x[10], y[10], n, path[10], optimal_path[10];
double dist[10][10];

static double get_dist(int from, int to) {
  int x_dist = abs(x[from]-x[to]);
  int y_dist = abs(y[from]-y[to]);

  return sqrt(x_dist * x_dist + y_dist * y_dist) + 16;
}

int main(void)
{
  int tc = 1;
  while(sd(n), n) {
    repi(i, n) {
      scanf("%d %d", x+i, y+i);
      path[i] = i;
    }

    for(int i = 0; i < n; i++) {
      for(int k = i+1; k < n; k++) {
        dist[i][k] = dist[k][i] = get_dist(i, k);
      }
    }

    double min_len = INFINITY, len;
    do {
      len = 0;
      for(int i = 1; i < n; i++) {
        len += dist[path[i-1]][path[i]];
      }

      if(len < min_len) {
        min_len = len;
        memcpy(optimal_path, path, sizeof(int) * n);
      }
      min_len = min(min_len, len);
    }while(next_permutation(path, path+n));
    
    puts("**********************************************************");
    printf("Network #%d\n", tc);

    for(int i = 1; i < n; i++) {
      int from = optimal_path[i-1], to = optimal_path[i];

      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
          x[from], y[from], x[to], y[to], dist[from][to]);
    }

    printf("Number of feet of cable required is %.2lf.\n", min_len);

    tc++;
  }
  
  return 0;
}
