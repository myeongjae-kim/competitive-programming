#include <vector>
#include <cstdio>

using namespace std;

typedef vector<int> vi;

class UnionFind
{
private: vi p, rank, size; int numSets;
public:
  UnionFind (int N) {
    p.assign(N, 0);
    size.assign(N, 0);
    rank.assign(N, 0);
    numSets = N;
    for(int i = 0; i < N; i++) {
      p[i] = i;
      size[i] = 1;
    }
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if(!isSameSet(i,j)) {
      int x = findSet(i), y = findSet(j);
      if(rank[x] > rank[y]) {
        p[y] = x;
        size[x] += size[y];
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
        size[y] += size[x];
      }
      numSets--;
    }
  }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return size[findSet(i)]; }
};

int main() {
  printf("Assume that there are 5 disjoint sets initially\n");
  UnionFind UF(5); // create 5 disjoint sets
  printf("%d\n", UF.numDisjointSets()); // 5
  UF.unionSet(0, 1);
  printf("%d\n", UF.numDisjointSets()); // 4
  UF.unionSet(2, 3);
  printf("%d\n", UF.numDisjointSets()); // 3
  UF.unionSet(4, 3);
  printf("%d\n", UF.numDisjointSets()); // 2
  printf("isSameSet(0, 3) = %d\n", UF.isSameSet(0, 3)); // will return 0 (false)
  printf("isSameSet(4, 3) = %d\n", UF.isSameSet(4, 3)); // will return 1 (true)
  for (int i = 0; i < 5; i++) // findSet will return 1 for {0, 1} and 3 for {2, 3, 4}
    printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
  UF.unionSet(0, 3);
  printf("%d\n", UF.numDisjointSets()); // 1
  for (int i = 0; i < 5; i++) // findSet will return 3 for {0, 1, 2, 3, 4}
    printf("findSet(%d) = %d, sizeOfSet(%d) = %d\n", i, UF.findSet(i), i, UF.sizeOfSet(i));
  return 0;
}
