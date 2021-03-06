// Range sum queries
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  vi st, A;
  int n;

  int left (int p) { return p << 1; } // same as binary heap operations
  int right (int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L];
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
      st[p] = A[i];
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
      st[p] = A[L];
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
  SegmentTree(const vi &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0); // create large enough vector
    build(1, 0, n - 1);
  }
  int rsq(int i, int j) { return rsq(1, 0, n-1, i, j); }
  void update(int i, int value) {
    A[i] = value;
    update(1, 0, n-1, i);
  }
  void update_range(int i, int j, vi new_numbers) {
    assert(j-i+1 == (int)new_numbers.size());
    for(int k=i; k <= j; k++) {
      A[k] = new_numbers[k-i];
    }

    update_range(1, 0, n-1, i, j);
  }

};

int main(void)
{
  int arr[] = { 10, 2, 47, 3, 7, 9, 1, 98, 21 };
  vi A(arr, arr + 9);
  SegmentTree st(A);
  printf("rsq(1, 7) = %d\n", st.rsq(1, 7)); // 167
  printf("rsq(3, 8) = %d\n", st.rsq(3, 8)); // 139

  st.update(4, 17);
  printf("rsq(1, 7) = %d\n", st.rsq(1, 7)); // 177
  printf("rsq(3, 8) = %d\n", st.rsq(3, 8)); // 149

  st.update_range(3, 7, {10, 20, 30, 40, 50});
  // arr[] = { 10, 2, 47, 10, 20, 30, 40, 50, 21 };
  printf("rsq(1, 7) = %d\n", st.rsq(1, 7)); // 199
  printf("rsq(3, 8) = %d\n", st.rsq(3, 8)); // 171

  return 0;
}
