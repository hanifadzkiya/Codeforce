#include <bits/stdc++.h>
using namespace std;

long long n,d,changes,battles,selisih,minutes,data[200005],maks;

int main(){
	cin >> n >> d;
	battles = n;
	changes = 0;
	maks = 0;
	for(int i = 0;i<d;i++){
		cin >> data[i];
		changes += data[i];
		battles += data[i];
		if(n - battles > maks){
			maks = n - battles;
		}
		if(battles <= 0){
			cout << i + 1 << endl;
			return 0;
		}
	}
	if(battles >= n){
		cout << -1 << endl;
	} else {
		selisih = n - battles;
		if((n - maks) % selisih > 0){
			minutes = ((n - maks) / selisih + 1)*d;
			battles = n - selisih*((n - maks) / selisih + 1);
		} else { 
			minutes = ((n - maks) / selisih)*d;
			battles = maks;
		}
		for(int i = 0;i<d;i++){
			battles = battles + data[i];
			if(battles <= 0){
				cout << minutes + i + 1 << endl;
				return 0;
			}	
		}
	}
}
