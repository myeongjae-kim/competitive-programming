#include <cmath>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int count_sub_square(vector<string> &A, vector<string> &B, int a, int b){
  int count = 0;

  for(int r = 0; r <= a-b; r++) {
    for(int c = 0; c <= a-b; c++) {

      for(int r_s = 0; r_s < b; r_s++) {
        for(int c_s = 0; c_s < b; c_s++) {
          if(A[r+r_s][c+c_s] == B[r_s][c_s]) {
          
          } else {
            goto next_point;
          }
        }
      }
      count++;
next_point:;
    }
  }

  return count;
}

void rotate_square(vector<string> &A, int a) {
  int layer = a/2;

  for(int i = 0; i < layer; i++) {
    for(int k = i; k < a-1-i; k++) {
      char temp = A[i][k];
      A[i][k] = A[a-1-k][i];
      A[a-1-k][i] = A[a-1-i][a-1-k];
      A[a-1-i][a-1-k] = A[k][a-1-i];
      A[k][a-1-i] = temp;
    }
  }

  /*
  for(auto &s : A) {
    for(auto c : s) {
      cout << c;
    }
    cout << endl;
  }
  cout << endl;
  */
}

int main(void)
{
  ios::sync_with_stdio(0); cin.tie(0);
  int a,b;
  while(cin>>a>>b, a || b) {
    vector<string> A, B;
    string s_buf;

    for(int i=0;i<a;i++) {
      cin>>s_buf;
      A.push_back(s_buf);
    }

    for(int i=0;i<b;i++) {
      cin>>s_buf;
      B.push_back(s_buf);
    }

    int ans = count_sub_square(A,B,a,b);
    rotate_square(B,b);
    cout << ans;
    for(int i = 0; i < 3; i++) {
      ans = count_sub_square(A,B,a,b);
      rotate_square(B,b);
      cout << ' '<< ans;
    }
    cout << endl;

  }

  return 0;
}
