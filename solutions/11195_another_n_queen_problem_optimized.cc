#include <stdio.h>
#include <sstream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <bitset>

using namespace std;

int n;
char board[20][20];
int count;

bitset<30> rw, ld, rd;

void backtrack(int c) {
  if(c == n) {
    count++;
    return ;
  }

  for(int r = 0; r < n; r++) {
    if(board[r][c] != '*'
      && rw[r] == false
      && rd[r+c] == false
      && ld[r-c+n-1] == false) {

      rw[r] = rd[r+c] = ld[r-c+n-1] = true;
      backtrack(c+1);
      rw[r] = rd[r+c] = ld[r-c+n-1] = false;
    }
  }
}

int main(void) {
  int t = 0;
  while(scanf("%d", &n), n) {
    t++;
    memset(board, 0, sizeof board);
    rw.reset();
    ld.reset();
    rd.reset();
    count = 0;

    for(int i = 0; i < n; i++)
      scanf("%s", board[i]);

    backtrack(0);
    printf("Case %d: %d\n", t, count);
  }
  return 0;
}
