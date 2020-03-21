#include <iostream>
#include <sstream>
#include <cassert>

using namespace std;

int n;
int seq[100005];

typedef struct C {
  int p;
  int m;
  int z;

  struct C operator+(struct C &rhs) {
    return {p + rhs.p, m + rhs.m, z + rhs.z};
  }
} C;

C st[100005 * 4];

void update(int p, int L, int R, int idx, int value) {
  if(L == idx && R == idx) {
    assert(L == idx);
    assert(R == idx);

    seq[L] = value;

    st[p].p = seq[L] > 0 ? 1 : 0;
    st[p].m = seq[L] < 0 ? 1 : 0;
    st[p].z = seq[L] == 0 ? 1 : 0;
    return;
  }

  // out of range
  if(L > idx || R < idx) {
    return;
  }

  update(p<<1, L, (L+R)/2, idx, value);
  update(p<<1|1, (L+R)/2 + 1, R, idx, value);

  st[p] = st[p<<1] + st[p<<1|1];
}

void update(int idx, int value) {
  update(1, 0, n-1, idx, value);
}

void build(int p, int L, int R) {
  if(L == R) {
    st[p].p = seq[L] > 0 ? 1 : 0;
    st[p].m = seq[L] < 0 ? 1 : 0;
    st[p].z = seq[L] == 0 ? 1 : 0;
    return;
  }

  build(p<<1, L, (L+R)/2);
  build(p<<1|1, (L+R)/2 + 1, R);

  st[p] = st[p<<1] + st[p<<1|1];
}

void build() {
  build(1, 0, n-1);
}

C query(int p, int L, int R, int i, int k) {
  if(i <= L && R <= k) {
    return st[p];
  }

  if(L > k || R < i) {
    return {0,0,0};
  }

  C r1 = query(p<<1, L, (L+R)/2, i, k);
  C r2 = query(p<<1|1, (L+R)/2+1, R, i, k);

  return r1 + r2;
}

char query(int i, int k) {
  C &&r = query(1, 0, n-1, i, k);
  if(r.z > 0) {
    return '0';
  } else if (r.m > 0 && (r.m & 1)) {
    return '-';
  } else {
    //assert(r.p > 0);
    return '+';
  }
}

int main(void)
{
  int k;
  string s;
  while(getline(cin, s), !cin.eof()) {
    stringstream ss(s);
    ss >> n >> k;

    // cout << n << ' ' << k << endl;

    for(int i = 0; i < n; i++) {
      cin >> seq[i];
      // cout << seq[i] <<' ';
    }
    // cout << endl;
    build();

    char cmd; int i, j;
    getline(cin, s);
    for(int z = 0; z < k; z++) {
      getline(cin, s);
      stringstream ss(s);
      ss >> cmd >> i >> j;
      // cout << cmd << ' ' << i << ' ' << j << endl;
      switch(cmd) {
        case 'C':
          update(i-1, j);
          break;
        case 'P':
          cout << query(i-1, j-1);
          break;
        default:
          assert(false);
      }
    }
    cout << endl;
  }
  return 0;
}
