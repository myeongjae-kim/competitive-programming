// range minimum query
#include <cstdio>
#include <vector>
#include <cassert>
#include <iostream>

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
      st[p] = L;
    else {
      build(left(p), L, (L+R)/2);
      build(right(p), (L+R)/2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
  }

  // Range Minimum Query
  int rmq(int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1; // outside query range
    if (i <= L && R <= j) return st[p];

    int p1 = rmq(left(p), L, (L+R)/2, i, j);
    int p2 = rmq(right(p), (L+R)/2+1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
  }

  // Update
  void update(int p, int L, int R, int i) {
    // base case
    if(L == i && R == i) {
      return;
    }

    // recursion
    if(L <= i && i <= (L+R)/2) {
      update(left(p), L, (L+R)/2, i);
    } else {
      update(right(p), (L+R)/2 + 1, R, i);
    }

    st[p] = (A[st[left(p)]] < A[st[right(p)]]) ? st[left(p)] : st[right(p)];
  }

  void update_range(int p, int L, int R, int i, int j) {
    // base case
    if(L == R) {
      return;
    }

    if(R < i || L > j) {
      return;
    } 

    update_range(left(p), L, (L+R)/2, i,j);
    update_range(right(p), (L+R)/2 + 1, R, i,j);

    st[p] = A[st[left(p)]] < A[st[right(p)]] ? st[left(p)] : st[right(p)];
  }

public:
  SegmentTree(const vi &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0); // create large enough vector
    build(1, 0, n - 1);
  }
  int rmq(int i, int j) { return rmq(1, 0, n-1, i, j); }
  void update(int i, int value) { 
    A[i] = value;
    update(1, 0, n-1, i); 
  }

  void update_range(int i, int j, const vi & new_values) {
    assert((j-i+1) == (int)new_values.size());

    // update A
    for(int k = i; k <= j; k++) {
      A[k] = new_values[k-i];
    }

    // update segment tree
    update_range(1, 0, n-1, i, j);
  }

   void print_arr() {
    for(auto i : A) {
      printf("%d ", i);
    }
    putchar('\n');
   }

};

int main(void) {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 ,10 };         // the original array
  vi A(arr, arr + 10);                      // copy the contents to a vector
  SegmentTree st(A);

  cout << A[st.rmq(0, 9)] << endl;

  return 0;
}
