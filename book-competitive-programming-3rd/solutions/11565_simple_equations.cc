#include <cstdio>

int main(void)
{
  int n; scanf("%d", &n);

  while(n--) {
    int A, B, C; scanf("%d %d %d", &A, &B, &C);

    int x,y,z;
    x = y = z = 1;

    for(x = -99; x <= 99; x++) {
      if(x == 0) continue;
      for(y = x+1; y <= 99; y++) {
        if(y == 0 || B % (x*(long)y))
          continue;

        z = B / ((long)x * y);

        if(z <= y) continue;

        if((x + y + z == A)
              && ((x*x + y*y + z*z) == C)) {
          printf("%d %d %d\n", x, y, z);
          goto next;
        }

      }
    }
    printf("No solution.\n");
next:;
  }
  return 0;
}
