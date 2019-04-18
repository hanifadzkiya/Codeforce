#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,maks,hasil,cnt;
	int data[100002];
	cin >> n;
	maks = -1;
	for(int i = 0;i<n;i++){
		cin >> data[i];
		if(data[i] > maks){
			maks = data[i];
		}
	}
	hasil = -1;
	if(data[0] == maks){
		cnt = 1;
	} else {
		cnt = 0;
	}
	for(int i = 1;i<n;i++){
		if((data[i] != maks) && (data[i-1] == maks)){
			if(cnt > hasil){
				hasil = cnt;
			}
			cnt = 0;
		} else {
			if(data[i] == maks){
				cnt ++;
			}
		}
	}
	if(cnt > hasil){
		hasil = cnt;
	}
	cout << hasil << endl;
}