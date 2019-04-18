#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	for(int i = k-1;i>=1;i--){
		if(n % i == 0){
			cout << k*(n/(i))+i << endl;
			return 0;
		}
	}
}