#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
  int k;
  while(scanf("%d", &k) != EOF) {
    int x,y;
    vector< pair<int, int> > ans;
    
    x = y = 1;
    while(1) {
      y = 1;

      int lhs = x * y;
      int rhs = k * (x + y);

      int lhs2 = x * (y + 1);
      int rhs2 = k * (x + y + 1);

      int diff1 = rhs - lhs;
      int diff2 = rhs2 - lhs2;

      if(diff2 >= diff1
          || ((k * x) % (x-k))){
        x++;
        continue;
      }

      while(1) {
        lhs = x * y;
        rhs = k * (x + y);
        if(lhs == rhs) {
          ans.push_back(make_pair(y, x)); // y is bigger than x
          if(x == y) {
            goto next;
          }
          break;
        }
        y++;
      }
      x++;
    }

next:

    printf("%lu\n", ans.size());
    for(auto &p : ans) {
      printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
    }
  }
  return 0;
}
