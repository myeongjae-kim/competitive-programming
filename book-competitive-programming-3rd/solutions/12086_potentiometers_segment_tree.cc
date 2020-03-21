// Range sum queries
#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;

typedef vector<int> vi;

int n;
int A[200005];
int st[600005];

void build(int p, int L, int R) {
  if(L == R) {
    st[p] = A[L];
    return;
  }

  build(p<<1, L, (L+R)/2);
  build(p<<1|1, (L+R)/2 + 1, R);

  st[p] = st[p<<1] + st[p<<1|1];
}

void build() {
  build(1, 1, n);
}

void update(int p, int L, int R, int i, int diff) {
  // no updated value
  if( !(L <= i && i <= R) ) {
    return;
  }
  st[p] += diff;

  // base case
  if(L == R) {
    assert(L == i);
    assert(R == i);
    return;
  }

  update(p<<1, L, (L+R)/2, i, diff);
  update(p<<1|1, (L+R)/2 + 1, R, i, diff);
}

void update(int i, int new_value) {
  update(1, 1, n, i, new_value - A[i]);
  A[i] = new_value;
}

int rsq(int p, int L, int R, int i, int k) {
  // range is found
  if(i <= L && R <= k) 
    return st[p];
  
  // not in range
  if(i > R || k < L) 
    return 0;
  
  return rsq(p<<1, L, (L+R)/2, i, k) + rsq(p<<1|1, (L+R)/2+1, R, i, k);
}

int rsq(int i, int k) {
  return rsq(1, 1, n, i, k);
}

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);

  int t = 1;

  while(cin >> n, n) {
    if(t != 1) cout << endl;
    cout << "Case " << t <<":" << endl;
    for(int i = 1; i <= n; i++) {
      cin >> A[i];
    }

    build();

    string s;
    // remove \n
    getline(cin, s);
    while(getline(cin,s), s != "END") {
      stringstream ss(s);

      char cmd; ss >> cmd;
      int n1, n2; ss >> n1 >> n2;

      switch(cmd) {
        case 'S':
            update(n1, n2);
          break;
        case 'M':
            cout << rsq(n1, n2) << endl;
          break;

        default:
          assert(false);
      }
    }

    
    t++;
  }

  return 0;
}
