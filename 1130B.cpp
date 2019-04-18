#include <bits/stdc++.h>
using namespace std;

long long n,sasha[100005],dina[100005],s,d,a,sum;
int main(){
	cin >> n;
	memset(dina,-1,sizeof dina);
	memset(sasha,-1,sizeof sasha);
	for(int i = 0;i<=n;i++){
		sasha[i] = -1;
		dina[i] = -1;
	}
	for(int i = 1;i<=2*n;i++){
		cin >> a;
		if(sasha[a] == -1){
			sasha[a] = i;
		} else {
			dina[a] = i;
		}
	}

	sum = 0;
	s = 1;
	d = 1;
	for(int i = 1;i<=n;i++){
		sum = sum + abs(sasha[i] - s) + abs(dina[i] - d);
		s = sasha[i];
		d = dina[i];
	}
	cout << sum << endl;
}