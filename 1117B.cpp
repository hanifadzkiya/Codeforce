#include <bits/stdc++.h>
using namespace std;

long long n,m,k,maks1,maks2,sisa,nilai,a,b,data[200005];

int main(){
	cin >> n >> m >> k;
	maks1 = -1;
	maks2 = -2;
	for(int i = 0;i<n;i++){
		cin >> data[i];
		if(data[i] > maks1){
			maks2 = maks1;
			maks1 = data[i];
		} else {
			if(data[i] > maks2){
				maks2 = data[i];
			}
		}
	}
	//yang jadi dulu
	nilai = (m / (k+1))*maks1*k + (m / (k+1))*maks2;
	sisa = m % (k+1);
	nilai = nilai + sisa*maks1;
	cout << nilai << endl; 
}