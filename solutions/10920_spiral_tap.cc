#include <cstdio>
#include <cassert>

int main(void)
{
  int a,n;
  while(scanf("%d %d", &a, &n), a||n) {
    int max_num=3;

    int row,col;
    row=col=(a+1)/2;

    if(a == 1) {
      printf("Line = %d, column = %d.\n", row, col);
      continue;
    }

    while(n > max_num * max_num) {
      max_num +=2;
      row++,col++;
    }

    int current=(max_num-2) * (max_num-2);
    int gap = max_num-1;

    if(current != n) {
      current++;
      row++;
    } else {
      goto answer;
    }

    for(int i = 0; i < gap-1; i++) {
      if(current != n) {
        current++;
        col--;
      } else {
        goto answer;
      }
    }

    for(int i = 0; i < gap; i++) {
      if(current != n) {
        current++;
        row--;
      } else {
        goto answer;
      }
    }

    for(int i = 0; i < gap; i++) {
      if(current != n) {
        current++;
        col++;
      } else {
        goto answer;
      }
    }

    for(int i = 0; i < gap; i++) {
      if(current != n) {
        current++;
        row++;
      } else {
        goto answer;
      }
    }

    assert(current == n);
answer:
    printf("Line = %d, column = %d.\n", row, col);
  }
  
  return 0;
}
