#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int front[15];
int rear[15];
vector<double> v;

int main(void)
{
  int f, r;
  while(scanf("%d %d", &f, &r) != EOF && f) {
    for(int i = 0; i < f; i++) {
      scanf("%d", &front[i]);
    }
    for(int i = 0; i < r; i++) {
      scanf("%d", &rear[i]);
    }

    v.clear();

    for(int i = 0; i < f; i++) {
      for(int k = 0; k < r; k++) {
        v.push_back(((double)rear[k]) / front[i]);
      }
    }

    sort(v.begin(), v.end(), [](double a, double b) {
          return a > b;
        });

    double max_ratio = 0;

    for(int i = 0; i < v.size()-1; i++) {
      max_ratio = max(max_ratio, v[i]/v[i+1]);
    }

    printf("%.2f\n", max_ratio);
  }
  return 0;
}
