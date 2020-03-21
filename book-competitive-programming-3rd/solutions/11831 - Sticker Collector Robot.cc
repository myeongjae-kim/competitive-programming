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

#define NO 0
#define EA 1
#define SO 2
#define WE 3

int N, M, S, r, c;
int dir;
char v[102][102];
string inst;

void print_map() {
  repi(i, N) {
    repi(k, M) {
      fprintf(stderr, "%c", v[i][k]);
    }
    fprintf(stderr, "\n");
  }
}


int sol(int r, int c, int dir, string &inst) {
  int ans = 0;
  int next_r, next_c;
  for(auto i : inst) {
    // trace1(c);
    switch(i) {
      case 'D':
        dir++; dir %= 4;
        break;

      case 'E':
        dir += 3; dir %= 4;
        break;

      case 'F':
        switch(dir) {
          case NO:
            next_r = r - 1;
            next_c = c;
            break;

          case EA:
            next_r = r;
            next_c = c + 1;
            break;

          case SO:
            next_r = r + 1;
            next_c = c;
            break;

          case WE:
            next_r = r;
            next_c = c - 1;
            break;

          default:
            break;
        }

        if( !(0 <= next_r && next_r < N) 
            || !(0 <= next_c && next_c < M)
            || v[next_r][next_c] == '#') {
          // do nothing
        } else {
          r = next_r; c = next_c;
          if (v[r][c] == '*'){
            ans++;
            v[r][c] = '.';
          }
        }

        break;

      default:
        break;
    }
  }

  return ans;
}


int main(void)
{
  while(scanf("%d %d %d", &N, &M, &S), N||M||S) {
    string s;
    getline(cin, s);

    repi(i, N) {
      getline(cin, s);
      repi(k ,M) {
        v[i][k] = s[k];

        switch(v[i][k]) {
          case 'N':
            r = i; c = k;
            dir = NO;
            break;
          case 'S':
            r = i; c = k;
            dir = SO;
            break;
          case 'L': // East
            r = i; c = k;
            dir = EA;
            break;
          case 'O': // West
            r = i; c = k;
            dir = WE;
            break;
          default:
            break;
        }
      }
    }
    getline(cin, inst);

    // trace4(N,M,S,inst);
    // print_map();
    // trace4(r, c, dir, inst);
    
    printf("%d\n", sol(r, c, dir, inst));
  }
  
  return 0;
}
