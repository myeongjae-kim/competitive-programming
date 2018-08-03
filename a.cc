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
int row, col;
bool is_b;
string s;
string buf;
int idx;
string ans;

int b[202][202];

void comp(int r, int r_size, int c, int c_size) {
  bool has_1, has_0, has_both;
  has_1 = has_0 = has_both = false;

  for(int i = r; i < r + r_size; i++) {
    for(int k = c; k < c + c_size; k++) {
      if(b[i][k]) {
        has_1 = true;
      } else {
        has_0 = true;
      }

      if(has_1 && has_0) {
        has_both = true;
        goto exit_loop;
      }
    }
  }

exit_loop:
  if(has_both) {
    // recursion
    ans += 'D';
    
    int row_big_size;
    int row_small_size;
    int col_big_size;
    int col_small_size;
    
    row_big_size = r_size / 2 + (r_size & 1);
    row_small_size = r_size / 2;
    col_big_size = c_size / 2 + (c_size & 1);
    col_small_size = c_size / 2;

    // top left
    comp(r, row_big_size, c, col_big_size);
    
    // top right
    if(col_small_size != 0) {
      comp(r, row_big_size, c + col_big_size, col_small_size);
    }
    
    // bottom left
    if(row_small_size != 0) {
      comp(r + row_big_size, row_small_size, c, col_big_size);
    }
    
    // bottom right
    if(row_small_size != 0 && col_small_size != 0) {
      comp(r + row_big_size, row_small_size,
          c + col_big_size, col_small_size);
    }
    
  } else if(has_1) {
    ans += 1 + '0';
  } else {
    assert(has_0);
    ans += 0 + '0';
  }
}

void comp() {

  int idx = 0;
  repi(i, row) {
    repi(k, col) {
      b[i][k] = s[idx++] - '0';
    }
  }

  comp(0, row, 0, col);
}


void decomp(int r, int r_size, int c, int c_size) {
  char kind = s[idx++];

  // recursion
  if(kind == 'D') {
    int row_big_size;
    int row_small_size;
    int col_big_size;
    int col_small_size;
    
    row_big_size = r_size / 2 + (r_size & 1);
    row_small_size = r_size / 2;
    col_big_size = c_size / 2 + (c_size & 1);
    col_small_size = c_size / 2;

    // top left
    decomp(r, row_big_size, c, col_big_size);
    
    // top right
    if(col_small_size != 0) {
      decomp(r, row_big_size, c + col_big_size, col_small_size);
    }
    
    // bottom left
    if(row_small_size != 0) {
      decomp(r + row_big_size, row_small_size, c, col_big_size);
    }
    
    // bottom right
    if(row_small_size != 0 && col_small_size != 0) {
      decomp(r + row_big_size, row_small_size,
          c + col_big_size, col_small_size);
    }
  } else {
    assert(kind == '1' || kind == '0');
    for(int i = r; i < r + r_size; i++) {
      for(int k = c; k < c + c_size; k++) {
        b[i][k] = (kind == '1');
      }
    }
  }
}

void decomp() {
  idx = 0;
  decomp(0, row, 0, col);

  repi(i, row) {
    repi(k, col) {
      ans += b[i][k] + '0';
    }
  }
}

bool is_next_case(string& s) {
  if(s[0] == '#' || s[1] == ' ')
    return true;
}

int main(void)
{
  getline(cin, buf);
  while(true) {
    s.clear();
    ans.clear();
    SET(b,0);
    row = col = 0;

    if(buf[0] == '#')
      break;

    assert(buf[1] == ' ');

    is_b = buf[0] == 'B';

    stringstream ss(buf.substr(1));
    ss >> row >> col;
    
    // get input
    while(1) {
      getline(cin, buf);
      if(is_next_case(buf))
        break;

      s += buf;
    }

    // trace4(is_b, row, col, s);

    printf("%c %3d %3d\n", is_b ? 'D' : 'B', row, col);

    if(is_b) {
      comp();
    } else {
      decomp();
    }

    repi(i, ans.size()) {
      if(i > 0 && i % 50 == 0) {
        putchar('\n');
      }
      putchar(ans[i]);
    }
    putchar('\n');
  }


  return 0;
}
