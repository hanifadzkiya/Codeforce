#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,days,maks;
	cin >> n;
	days = 0;
	maks = 0;
	for(int i = 1;i<=n;i++){
		cin >> a;
		if(a > maks){
			maks = a;
		}
		if(maks == i){
			days++;
		}
	}
	cout << days << endl;
}