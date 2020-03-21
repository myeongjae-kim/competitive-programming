#include <stdio.h>

int main(void)
{
  int a,b;
  scanf("%d",&a);
  while(scanf("%d %d", &a, &b) != EOF) {
    if(a>b) printf(">\n");
    else if(a == b) printf("=\n");
    else printf("<\n");
  }
  return 0;
}
