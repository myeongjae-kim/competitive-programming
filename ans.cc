//Binary Search the answer

#include <bits/stdc++.h>
using namespace std;
#define MAX_ALPHA 52
typedef vector<int> vi;
typedef vector<vi> vvi;

//Note how I skipped trouble of thinking what happens when z-A happens
//We can take 256 as size and skipping subtraction at all
vvi v(100, vi());
string ss;

void sol(){
	int desIndex = 0;		//min index to search for
	int ssIndex = 0, lo = -1, hi;
	char cur = 0;

	while((cur = ss[ssIndex])){
		cur -= 'A';
		vi::iterator actIndex =  lower_bound(
			v[cur].begin(), v[cur].end(), desIndex);
		//lower_bound returns atleast desIndex
		
		//When alphabet missing
		if (actIndex == v[cur].end()){
			printf("Not matched\n");
			return;
		}
		else {
			if (lo == -1) lo = *actIndex;
			hi = *actIndex;
			desIndex = hi + 1;	//We have read desIndex in s 
		}
		ssIndex++;
	}
	printf("Matched %d %d\n", lo, hi);
}

int main(){
	char c;
	int serial = 0;
	int q;

	while((c = getchar()) != '\n'){
		v[c-'A'].push_back(serial++);
	}

	cin >> q;
	getchar();
	while(q--){
		getline(cin,ss);
		sol();
	}
	return 0;
}
