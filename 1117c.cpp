#include <bits/stdc++.h>
using namespace std;

long long a,b,x,y,l,r,c,d,n,sel2,sel,weeks,tmp;
string path;
bool suc;

long long count(long long weeks, long long x, long long y , long long a, long long b, long long c, long long d){
	//cout << x << ' ' << y << ' ' << a << ' ' << b << ' ' << c << ' ' << d <<' '<< weeks << ' ' << abs((x-(a+weeks*c))) + abs((y-(b+weeks*d))) <<  endl;
	return abs((x-(a+weeks*c))) + abs((y-(b+weeks*d)));
}

int main(){
	cin >> a >> b;
	cin >> x >> y;
	cin >> n;
	cin >> path;

	//Get Final Step If The Ships Don't Walk Anymore
	c = 0;
	d = 0;
	for(int i = 0;i<n;i++){
		if(path[i] == 'U') d++;
		if(path[i] == 'D') d--;
		if(path[i] == 'R') c++;
		if(path[i] == 'L') c--;
	}
	//Binary Search Steps
	l = 0;
	r = 1000000000;
	suc = false;
	while(l<r and suc == false){
		weeks = (l+r)/2;
		sel = count(weeks,x,y,a,b,c,d);
		if(sel > weeks*(n)){
			sel2 = count(weeks+1,x,y,a,b,c,d);
			if(sel2 <= (weeks+1)*(n)){
				suc = true;
			} else {
				l = weeks+1;
			}
		} else {
			r = weeks-1;
		}
	}

	weeks = (l+r)/2;
	sel = count(weeks,x,y,a,b,c,d);
	//cout << sel << ' ' << weeks*n+tmp << endl;
	if(sel >= weeks*n+tmp){
		tmp = 0;
		while(sel > weeks*n+tmp and tmp < n){
			if(path[tmp] == 'U') d++;
			if(path[tmp] == 'D') d--;
			if(path[tmp] == 'R') c++;
			if(path[tmp] == 'L') c--;
			sel = count(weeks,x,y,a,b,c,d);
			tmp++;
		}
		if(sel <= weeks*n+tmp){
			cout << weeks*n+tmp << endl;
		} else {
			cout << -1;
		}
	} else {
		cout << -1 << endl;
	}
}