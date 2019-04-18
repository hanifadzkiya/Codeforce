#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,pos,neg,zero,minim;
	cin >> n;
	pos = 0;
	neg = 0;
	zero = 0;
	for(int i = 0;i<n;i++){
		cin >> a;
		if(a == 0) zero++;
		if(a < 0) neg++;
		if(a > 0) pos++;
	}
	minim = n / 2;
	if(minim*2 < n) minim++;
	if(pos >= minim){
		cout << 1;
	} else {
		if(neg >= minim){
			cout << -1;
		} else {
			cout << 0;
		}
	}
	cout << endl;
}