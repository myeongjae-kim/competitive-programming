#include <cstdio>

struct c {
  char com[30];
  int low;
  int high;
};

int D;
struct c db[10004];

int main(void)
{
  int t; scanf("%d", &t);

  while(t--) {
    scanf("%d", &D);

    for(int i = 0; i < D; i++) {
      scanf("%s %d %d", db[i].com, &db[i].low, &db[i].high);
    }

    int Q; scanf("%d", &Q);

    for(int i = 0; i < Q; i++) {
      int value; scanf("%d", &value);
      int count = 0;
      int idx;
      for(int k = 0; k < D; k++) {
        if(db[k].low <= value && value <= db[k].high) {
          count++;
          idx = k;
          if(count > 1)
            break;
        }
      }
      if(count == 1) {
        printf("%s\n", db[idx].com);
      } else {
        printf("UNDETERMINED\n");
      }
    }

    if(t)
      putchar('\n');
  }
  return 0;
}
