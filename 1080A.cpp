#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,k,red,green,blue;
	cin >> n >> k;
	red = 2*n/k;
	if(2*n % k != 0) red ++;
	green = 5*n/k;
	if(5*n % k != 0) green ++;
	blue = 8*n/k;
	if(8*n % k != 0) blue ++;
	cout << red + green + blue << endl;
}