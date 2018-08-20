#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int v[102][102];

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  int N;

  while(cin >> N) {
    for (int i = 0; i < N; ++i) {
      for (int k = 0; k < N; ++k) {
        cin >> v[i][k]; 
        if(k > 0) v[i][k] += v[i][k-1];
      }
    }

    int ans = INT_MIN, local_ans;

    for (int c_from = 0; c_from < N; c_from++)
      for (int c_to = c_from; c_to < N; c_to++) {
        local_ans = 0;
        for(int i = 0; i < N; i++) {
          local_ans += v[i][c_to];
          if(c_from > 0) local_ans -= v[i][c_from-1];

          ans = max(ans, local_ans);

          if(local_ans < 0) local_ans = 0;
        }
      }

    printf("%d\n", ans);
  }

  return 0;
}
