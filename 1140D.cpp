#include <bits/stdc++.h>
using namespace std;

int main(){
	int sum = 0;
	int n;
	cin >> n;
	for(int i = 3;i<=n;i++){
		sum += i*(i-1);
	}
	cout << sum << endl;
}