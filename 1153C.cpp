#include <bits/stdc++.h>
#include <iostream>	
#define pb push_back
#define mp make_pair
#define f first
#define s second
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
int n,buka[10],tmp,udahada[10],tutup[10],hitung1,hitung,hitung2,hitung3,sampai;
string str;

int main(){
	cin >> n;
	cin >> str;
	int hitung = 0;
	rep(i,n){
		if(str[i] == '('){
			hitung++;
		}
	}
	if(n % 2 == 1 || hitung > n/2 || str[0] == ')' || str[n-1] == '('){
		cout << ":(" << endl;
		return 0;
	}
	sampai = n/2 - hitung;
	hitung2 = 0; // hitung )
	hitung3 = 0;
	rep(i,n){
		if(hitung2 > n/2){
			cout << ":(";
			return 0;
		}
		if(str[i] == ')'){
			hitung2++;
		} else {
			if(hitung3 < sampai && str[i] == '?'){
				str[i] = '(';
				hitung3++;
			}
		}
	}
	rep(i,n){
		if(str[i] == '?'){
			str[i] = ')';
		}
	}
	int t,b;
	b = 0;
	t = 0;
	rep(i,n){
		if(b == t && i != 0){
			cout << ":(" << endl;
			return 0;
		}
		if(str[i] == '(') b++;
		if(str[i] == ')') t++;
	}
	cout << str << endl;
}