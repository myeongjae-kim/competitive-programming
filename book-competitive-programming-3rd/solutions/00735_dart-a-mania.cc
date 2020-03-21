#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <set>

using namespace std;

unordered_set<int> s;
unordered_set<string> dup;

int main(void)
{
  int n;
  int first = true;

  // prepare scores
  s.insert(0);
  s.insert(50);
  for(int i = 1; i <= 20; i++) {
    s.insert(i);
    s.insert(i * 2);
    s.insert(i * 3);
  }

  while(scanf("%d", &n), n > 0) {
    int comb = 0;
    int perm = 0;

    dup.clear();

    if(first) {
      first = false;
    } else {
      for(int i = 0; i < 70; i++) {
        putchar('*');
      }
      putchar('\n');
    }

    for(auto i : s) {
      for(auto j : s) {
        for(auto k : s) {
          if(i + j + k == n) {
            perm++;
            int ary[3];
            ary[0] = i; ary[1] = j; ary[2] = k;
            // sort ary
            for(int i = 1; i < 3; i++) {
              for(int k = i; k > 0; k--) {
                if(ary[k-1] > ary[k]) {
                  swap(ary[k-1], ary[k]);
                }
              }
            }
            string key = to_string(ary[0]) + "," + to_string(ary[1]) + "," + to_string(ary[2]);
            if(dup.find(key) == dup.end()) {
              dup.insert(key);
              comb++;
            }
          }

        }
      }
    }
    if(comb) {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, comb);
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, perm);
    } else {
      printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
    }
  }

  for(int i = 0; i < 70; i++) {
    putchar('*');
  }
  putchar('\n');
  printf("END OF OUTPUT\n");

  return 0;
}
