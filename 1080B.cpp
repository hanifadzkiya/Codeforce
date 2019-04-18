#include <bits/stdc++.h>
using namespace std;

int main(){
	long long l,r,kiri,kanan;
	int n;
	cin >> n;
	while(n--){
		cin >> l >> r;
		l--;
		if((l-1) % 2 == 0){
			l++;
			kiri = ((l)/2)*-1;
		} else {
			kiri = (l/2);
		}
		if((r-1) % 2 == 0){
			r++;
			kanan = (r/2) * -1;
		} else {
			kanan = (r/2);
		}
		cout << kanan - kiri << endl;
	}
}