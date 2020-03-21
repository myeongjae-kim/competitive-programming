#include <cstdio>
#include <utility>
#include <vector>
#include <cstring>

using namespace std;

int arr[22];

int m;
pair<int, int> share[11]; // zone, people

int ans_cus;
int ans_loc[12];

vector<int> v;

int get_answer() {
  int ans = 0;
  for(int i : v) {
    ans += arr[i];
  }

  // subtract all duplicated common areas
  for(int i = 0; i < v.size(); i++) {
    for(auto &p : share) {
      if(p.first & (1<<v[i])) {
        ans -= p.second;
      }
    }
  }

  // add common areas once
  for(int i = 0; i < m; i++) {
    for(int k : v) {
      if(share[i].first & (1<<k)) {
        ans += share[i].second;
        break;
      }
    }
  }

  return ans;
}

void combination(int n, int r, int current) {
  if(v.size() == r) {
    int ans = get_answer();

    if(ans > ans_cus) {
      ans_cus = ans;
      for(int i = 0; i < r; i++) {
        ans_loc[i] = v[i];
      }
    }

    return;
  }

  for(int i = current; i <= n; i++) {
    v.push_back(i);
    combination(n, r, i + 1);
    v.pop_back();
  }
}

void combination(int n, int r) { // from 1 to n, select r elements
  v.clear();
  combination(n, r, 1);
}

int main(void)
{
  int n, r, ccount = 1;
  while(scanf("%d", &n), scanf("%d", &r), n || r) {
    for(int i = 0; i < n; i++) {
      scanf("%d", &arr[i+1]);
    }

    ans_cus = 0;
    memset(share, 0, sizeof(share));
    
    
    scanf("%d", &m);

    for(int i = 0; i < m; i++) {
      int map = 0, t, people;
      scanf("%d", &t);

      for(int k = 0; k < t; k++) {
        int zone; scanf("%d", &zone);
        map |= (1<<zone);
      }

      scanf("%d", &people);

      share[i].first = map;
      share[i].second = people;
    }

    // dbg
    /*
    for(int i = 0; i < n; i++) {
      printf("%d ", arr[i]);
    }
    putchar('\n');

    for(int i = 0; i < m; i++) {
      printf("%d, %d\n", share[i].first, share[i].second);
    }
    */
    combination(n, r);

    printf("Case Number  %d\n", ccount++);
    printf("Number of Customers: %d\n", ans_cus);
    printf("Locations recommended:");

    for(int i = 0; i < r; i++) {
      printf(" %d", ans_loc[i]);
    }

    printf("\n");
    printf("\n");
  }

  return 0;
}
