#include <iostream>
#include <cstring>

using namespace std;

int arr[1003];
int memo[1003][1003];

int main(void)
{
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  int c = 0;

  while(cin >> n, n) {
    c++;
    memset(memo, 0, sizeof memo);

    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    for(int i = 0; i < n; i++) {
      for(int k = 0; k < n; k++) {
        if( i != k)
          memo[i][k] = arr[i] + arr[k];
      }
    }

    int m; cin >> m;

    cout << "Case " << c << ":" << endl;
    for(int i = 0; i < m; i++) {
      int ans = -1;
      int q; cin >> q;
      for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
          if(i != k && ((ans == -1) || abs(memo[i][k] - q) < abs(ans - q))) {
            ans = memo[i][k];
          }
        }
      }
      cout << "Closest sum to " << q << " is " << ans << "." <<endl;
    }

  }

  return 0;
}
