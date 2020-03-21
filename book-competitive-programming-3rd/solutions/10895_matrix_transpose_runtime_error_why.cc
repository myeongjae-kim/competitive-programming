#include <vector>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;
typedef vector<int> vi;

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);

  int r,c;

  while( cin >> r >>c, !cin.eof()) {
    // vector< vii > g(r+1);
    vector< vii > g(10000);

    for(int i = 1; i <= r; i++) {
      int num_elem; cin >> num_elem;

      g[i].resize(num_elem);

      for(int k = 0; k < num_elem; k++) {
        cin >> g[i][k].first;
      }
      for(int k = 0; k < num_elem; k++) {
        cin >> g[i][k].second;
      }
    }

    // transpose

    vector< vii > t(10000);

    for(int i = 1; i <= r; i++) {
      for(auto &p : g[i]) {
        pair<int, int> elem(i, p.second);
        t[p.first].push_back(elem);
      }
    }

    swap(r, c);
    cout << r << ' ' << c << endl;

    for(int i = 1; i <= r; i++) {
      cout << t[i].size() << (t[i].size() ? " " : "");

      for(int k = 0; k < t[i].size(); k++) {
        if(k != 0) {
          cout << ' ';
        }
        cout << t[i][k].first;
      }
      cout << endl;

      for(int k = 0; k < t[i].size(); k++) {
        if(k != 0) {
          cout << ' ';
        }
        cout << t[i][k].second;
      }
      cout << endl;
    }
  }

  return 0;
}
