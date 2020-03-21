#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <climits>

using namespace std;

int n;
vector<string> v;
string s;

int main(void)
{
  while(scanf("%d", &n) != EOF) {
    v.clear();
    for(int i = 0; i < n; i++) {
      cin >> s;
      v.push_back(s);
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        if(v[i][j] != '1')
          continue;

        int min_far = INT_MAX;
        for(int k = 0; k < n; k++) {
          for(int l = 0; l < n; l++) {
            if(v[k][l] != '3')
              continue;

            int far = abs(i-k) + abs(j-l);
            min_far = min(min_far, far);
          }
        }
        ans = max(ans, min_far);
      }
    }


    cout << ans << endl;
  }
  return 0;
}
