#include <iostream>

using namespace std;

int arr[1003];

int main(void)
{
  ios::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;

  for(int z = 0; z < t; z++) {
    int elem; cin >> elem;

    for(int i = 0; i < elem; i++) {
      cin >> arr[i];
    }

    int count = 0;

    for(int i = 1; i < elem; i++) {
      for(int k = 0; k < i; k++) {
        if(arr[k] <= arr[i]) {
          count++;
        }
      }
    }

    cout << count << endl;
  }

  return 0;
}
