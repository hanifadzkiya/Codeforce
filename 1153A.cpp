#include <bits/stdc++.h>
#include <iostream>	
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
using namespace std;
typedef long long ll;
typedef long double ld;
const double PI = acos(-1.0);
const int inf = int(2e18);
const int _inf = -inf;
const int mod = 998244353;
const int N = 1e5 + 1333;

int n,t,maksimal,x,i,idx;

int main(){
	cin >> n >> t;
	maksimal = 100005;
	Rep(j,1,n){
		cin >> x >> i;
		while(x < t){
			x += i;
		}
		if(x < maksimal){
			maksimal = x;
			idx = j;
		}
	}
	cout << idx << endl;
}