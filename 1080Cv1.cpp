#include <bits/stdc++.h>
using namespace std;

long long cariwhite(long long x,long long a,long long b,long long c,long long d){
	if((x % 2 == 1) && (a % 2 == b % 2))
		return (x/2+1); 
	else 
		return (x/2);
}

int main(){
	long long n,a1,b1,c1,d1,a2,b2,c2,d2,white1,black1,x,y,cnt1,blacktotal,whitetotal,cnt,a3,b3,c3,d3,cnt3,black3,white3,black2,white2,cnt2,tmp;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> x >> y;
		cin >> a1 >> b1 >> c1 >> d1;
		cin >> a2 >> b2 >> c2 >> d2;
		cnt = x*y;
		whitetotal = cariwhite(cnt,1,1,x,y);
		blacktotal = cnt - whitetotal;
		cnt1 = (c1-a1+1)*(d1-b1+1);
		white1 = cariwhite(cnt1,a1,b1,c1,d1);
		black1 = cnt1-white1;
		cnt2 = (c2-a2+1)*(d2-b2+1);
		white2 = cariwhite(cnt2,a2,b2,c2,d2);
		black2 = cnt2-white2;
		whitetotal = whitetotal + black1 - white2;
		blacktotal = blacktotal - black1 + white2;
		//Cari long longersection
		if((c1 < a2) || (a1 > c2) || (b1 > d2) || (d1 < b2)){
			cout << whitetotal <<' '<<blacktotal<< endl;
		} else {
			a3 = max(a1,a2);
			b3 = max(b1,b2);
			c3 = min(c1,c2);
			d3 = min(d1,d2);
			cnt3 = (c3-a3+1)*(d3-b3+1);
			white3 = cariwhite(cnt3,a3,b3,c3,d3);
			black3 = cnt3 - white3;
			whitetotal = whitetotal - black3; 
			blacktotal = blacktotal + black3;
			cout << whitetotal << ' ' << blacktotal << endl;
		}
	}
}