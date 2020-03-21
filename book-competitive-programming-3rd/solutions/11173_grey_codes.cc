#include <stdio.h>

int main(void)
{
  int a,n,k;
  scanf("%d",&a);
  while(scanf("%d %d", &n, &k) != EOF) {
    int ans=k&(1<<(n-1));
    for(int i=n-1;i>0;i--) 
      ans |= ((((k & 1<<(i)) != 0) ^ ((k & 1<<(i-1)) != 0)) << (i-1));
    printf("%d\n", ans);
  }
  return 0;
}
