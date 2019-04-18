#include <bits/stdc++.h>
using namespace std;

long long n,i,l,r;
string tc;

int main(){
	cin >> n;
	cin >> tc;
	if(tc[0] != tc[n-1]){
		l = 1;
		while(tc[l] == tc[l-1]){
			l++;
		}
		i = n-2;
		while(tc[i] == tc[i+1]){
			i--;
		}
		r = n-i-1;
		cout << l+r+1 << endl;
	} else {
		bool sama = true;
		for(int i = 1;i<n;i++){
			if(tc[i] != tc[i-1]){
				sama = false;
			}
		}
		if(sama){
			cout << ((n*(n+1))/2)%998244353 << endl;
		} else {
			l = 1;
			while(tc[l] == tc[l-1]){
				l++;
			}
			i = n-2;
			while(tc[i] == tc[i+1]){
				i--;
			}
			r = n-i-1;
			cout << (l*r+l+r+1)%998244353 << endl;
		}
	}
}
