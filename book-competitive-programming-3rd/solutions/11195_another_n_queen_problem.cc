#include <stdio.h>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <bitset>

using namespace std;

int n;
char board[20][20];

bitset<30> rw, ld, rd;

bool place(int r, int c) {
  if(board[r][c] != '*'
      && rw[r] == false
      && rd[r+c] == false
      && ld[r-c+n-1] == false) {
    return rw[r] = rd[r+c] = ld[r-c+n-1] = true;
  }
  
  return false;
}

void unplace(int r, int c) {
  rw[r] = rd[r+c] = ld[r-c+n-1] = false;
}

int backtrack(int c) {
  if(c == n) {
    return 1;
  }

  int count = 0;

  for(int r = 0; r < n; r++) {
    if(place(r, c)) {
      count += backtrack(c+1);
      unplace(r,c);
    }
  }
  return count;
}

int main(void) {
  int t = 0;
  while(scanf("%d", &n), n) {
    t++;
    memset(board, 0, sizeof board);
    rw.reset();
    ld.reset();
    rd.reset();

    for(int i = 0; i < n; i++)
      scanf("%s", board[i]);

    printf("Case %d: %d\n", t, backtrack(0));
  }
  return 0;
}
