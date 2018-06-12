#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int nums[3003];
bool res[3003];

int main(void)
{
  int n;
  while(scanf("%d", &n) != EOF) {
    memset(res, 0, sizeof(res));
    bool not_jolly = false;

    for(int i = 0; i < n; i++) {
      scanf("%d", &nums[i]);
    }

    for(int i = 1; i < n; i++) {
      int diff = abs(nums[i] - nums[i-1]);

      if(1 <= diff && diff <= n-1 && res[diff] == 0) {
        res[diff] = 1;
      } else {
        not_jolly = true;
        break;
      }
    }

    if(not_jolly) {
      printf("Not jolly\n");
    } else {
      printf("Jolly\n");
    }
  }
  return 0;
}
