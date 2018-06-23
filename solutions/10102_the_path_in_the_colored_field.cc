#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <climits>

using namespace std;

int n;
vector<string> v;
string s;

vector< pair<int, int> > ones;
vector< pair<int, int> > threes;

int main(void)
{
  while(scanf("%d", &n) != EOF) {
    v.clear();
    ones.clear();
    threes.clear();
    for(int i = 0; i < n; i++) {
      cin >> s;
      v.push_back(s);
    }

    for(int i = 0; i < n; i++) {
      for(int k = 0; k < n; k++) {
        if(v[i][k] == '1') {
          ones.push_back(make_pair(i,k));
        } else if(v[i][k] == '3') {
          threes.push_back(make_pair(i,k));
        }
      }
    }

    // get each minimal step
    // get max among minimal steps
    int ans = 0;

    for(auto &one : ones) {
      int local_min = INT_MAX;
      for(auto &three : threes) {
        int far = 0;
        far += abs(one.first - three.first) + abs(one.second - three.second);
        local_min = min(local_min, far);
      }
      ans = max(ans, local_min);
    }

    cout << ans << endl;
  }
  return 0;
}
