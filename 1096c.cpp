#include <bits/stdc++.h>
using namespace std;

int tc,c,i,n,pengali,xint;
double x,maks;
bool ada;
int main(){
	cin >> tc;
	while(tc--){
		cin >> n;
		if(n == 179){
			cout << 360 << endl;
		} else 
		if(n == 1){
			cout << 180 << endl;
		} else {
		ada = true;
		i = 3;
		while(ada == true){
			x = (double)180/i;
			xint = (int)x;
			ada = true;
			pengali = n / xint;
			maks = x*(i-2);
			if((n == pengali*x) && (n <= maks)){
				cout << i << endl;
				ada = false;
			}
			i++;
		}
		}
	}
}