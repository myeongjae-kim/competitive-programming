// Range sum queries
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  string A;
  vi st;
  int n;

  int left (int p) { return p << 1; } // same as binary heap operations
  int right (int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L] - '0';
    else {
      build(left(p), L, (L+R)/2);
      build(right(p), (L+R)/2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
    }
  }

  // Range Sum Query
  int rsq(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1; // outside query range
    if (i <= L && R <= j) return st[p];

    int p1 = rsq(left(p), L, (L+R)/2, i, j);
    int p2 = rsq(right(p), (L+R)/2+1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return p1 + p2;
  }

  // Update
  int update(int p, int L, int R, int i) {
    // base case
    if(L == i && R == i) {
      st[p] = A[i] - '0';
      return st[left(p/2)] + st[right(p/2)];
    }

    if(L <= i && i <= (L+R)/2) {
      st[p] = update(left(p), L, (L+R)/2, i);
    } else {
      st[p] = update(right(p), (L+R)/2 + 1, R, i);
    }
    return st[left(p/2)] + st[right(p/2)];
  }

  void update_range(int p, int L, int R, int i, int j) {
    // base case
    if(L == R) {
      st[p] = A[L] - '0';
      return;
    }

    // out of updating range
    if(R < i || L > j) {
      return;
    }

    update_range(left(p), L, (L+R)/2, i, j);
    update_range(right(p), (L+R)/2 + 1, R, i, j);

    st[p] = st[left(p)] + st[right(p)];
  }

public:
  SegmentTree(const string &_A) {
    A = _A;
    n = (int)A.length();
    st.assign(4 * n, 0); // create large enough vector
    build(1, 0, n - 1);
  }
  int rsq(int i, int j) { return rsq(1, 0, n-1, i, j); }
  void update(int i, char value) {
    A[i] = value;
    update(1, 0, n-1, i);
  }

  void update_range(int i, int j, string new_numbers) {
    assert(j-i+1 == (int)new_numbers.length());
    for(int k=i; k <= j; k++) {
      A[k] = new_numbers[k-i];
    }
  }

  void F(int i, int j) {
    for(int k = i; k <= j; k++) {
      A[k] = '1';
    }
  }

  void E(int i, int j) {
    for(int k = i; k <= j; k++) {
      A[k] = '0';
    }
  }

  void I(int i, int j) {
    for(int k = i; k <= j; k++) {
      A[k] = A[k] ? '0' : '1';
    }
  }

  void S(int i, int j) {
    update_range(1, 0, n-1, i, j);
  }

};

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int t; cin >> t;

  for(int z = 1; z <= t; z++) {
    cout << "Case " << z << ":" << endl;

    string s;

    // string making process
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
      int iter; cin >> iter;
      string str; cin >> str;
      for(int k = 0; k < iter; k++) {
        s += str;
      }
    }

    //cout << s << endl;
    SegmentTree st(s);

    // Queries
    cin >> n;
    int num_q = 1;
    for(int i = 0; i < n; i++) {
      char c; int idx1, idx2;
      cin >> c >> idx1 >> idx2;

      switch(c) {
        case 'F':
          st.F(idx1, idx2);
          break;
        case 'E':
          st.E(idx1, idx2);
          break;
        case 'I': 
          st.I(idx1, idx2);
          break;
        case 'S':
          st.S(idx1, idx2);
          cout << 'Q' << num_q++ <<": " << st.rsq(idx1, idx2) << endl;
          break;

        default:
          assert(false);
      }
      //cout << c << ' ' << idx1 << ' ' << idx2 << endl;
    }

  }

  return 0;
}
