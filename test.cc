#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  vector<int> v = {10,3,8,2};

  auto it = lower_bound(v.begin(), v.end(), 8);
  auto it_mid = v.begin() + 2;

  cout << (it == it_mid) << endl;
  
  return 0;
}
