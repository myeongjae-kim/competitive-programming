#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int main(void)
{
  int a,b,c,d;
  long long s, p;

  /* (a + b + c) / (a*b*c-1) == d
   * (a*b*c) > 1 */

  for(a = 1; a*4 <= 2000; a++) 
    for(b = a; a+b*3 <= 2000; b++)
      for(c = b; a+b+c+c <= 2000; c++) {
        s = (long long)(a+b+c);
        p = (long long)a * b * c;

        if(p <= 1000000 || 
            ((s * 1000000) % (p - 1000000)) )
          continue;

        d = (s * 1000000) / (p - 1000000);

        // a b c are already sorted.
        // If we print answer only when d is greater or equal than c,
        // the answer is unique and sorted.
        
        if(a+b+c+d > 2000 || d < c) {
          continue;
        }
        printf("%.2lf %.2lf %.2lf %.2lf\n",
            a / 100.0, b/100.0, c/100.0, d/100.0);
      }
  return 0;
}
