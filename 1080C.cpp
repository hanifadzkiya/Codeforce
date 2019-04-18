#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,n,m,hitam,hitam1,putih,putih1,a1,b1,c1,d1,total1,total;
	cin >> x;
	while(x--){
		cin >> n >> m;
		total = n*m;
		hitam = total/2;
		putih = total - hitam;
		cin >> a1 >> b1 >> c1 >> d1;
		total1 = (c1-a1+1)*(d1-b1+1);
		if((a1*b1) % 2 == 0){
			putih1 = putih;
			putih += total1 /2;
			hitam -= (total1 - (putih - putih1));
		} else {
			hitam1 = putih;
			hitam -= (total1/ 2);
			putih += (total1 - (hitam1 - hitam));
		}
		cout << putih << ' ' << hitam;
		cin >> a2 >> b2 >> c2 >> d2;
		
	}
}