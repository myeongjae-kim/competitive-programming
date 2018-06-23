#include <cstdio>

int arr[15];

int main(void)
{
  int n;
  bool first = true;
  while(scanf("%d", &n), n) {
    if(first) {
      first = false;
    } else {
      putchar('\n');
    }

    for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i]);
    }
    for(int a = 0; a - 6 < n; a++) {
      for(int b = a + 1; b - 4 < n; b++) {
        for(int c = b + 1; c - 3 < n; c++) {
          for(int d = c + 1; d - 2 < n; d++) {
            for(int e = d + 1; e - 1 < n; e++) {
              for(int f = e + 1; f < n; f++) {
                printf("%d %d %d %d %d %d\n",
                    arr[a], arr[b], arr[c], arr[d], arr[e], arr[f]);
              }
            }
          }
        }
      }
    }
  }
  
  return 0;
}
