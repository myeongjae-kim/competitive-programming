// Range sum queries
#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>

using namespace std;

typedef vector<int> vi;

int n;
vi ft;

#define LSOne(x) ((x) & -(x))

int rsq(int b) {
  int sum = 0;
  for (; b; b-= LSOne(b))
    sum += ft[b];
  return sum;
}

int rsq(int a, int b) {
  return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}

void adjust(int k, int v) {
  for(; k < (int)ft.size(); k += LSOne(k))
    ft[k] += v;
}

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);

  int t = 1;

  while(cin >> n, n) {
    ft.assign(n + 1, 0);

    if(t != 1) cout << endl;
    cout << "Case " << t <<":" << endl;

    int temp_i;
    for(int i = 1; i <= n; i++) {
      cin >> temp_i;
      adjust(i, temp_i);
    }

    string s;
    // remove \n
    getline(cin, s);
    while(getline(cin,s), s != "END") {
      stringstream ss(s);

      char cmd; ss >> cmd;
      int n1, n2; ss >> n1 >> n2;

      switch(cmd) {
        case 'S':
          adjust(n1, n2 - rsq(n1, n1));
          break;
        case 'M':
          cout << rsq(n1, n2) << endl;
          break;

        default:
          assert(false);
      }
    }
    
    t++;
  }

  return 0;
}
