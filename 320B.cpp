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
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef long double ld;
const double PI = acos(-1.0);
const int inf = int(2e18);
const int _inf = -inf;
const int mod = 998244353;
const int N = 1e5 + 1333;

int a,x,y,n,idx[105];
bool udah;
vi range[105];
void dfs(int idx,int it){
	if(it == y){
		udah = true;
	}
	cek[idx] = 1;
	if(idx <= range[y].f){
		Rep(i,idx+1,range[it].s){
			rep(j,tempat[i].size()){
				if(cek[tempat[i][j]] == -1){
					dfs(i,cek[tempat[i][j]]);
				}
			}
		}
	}
}

int main(){
	cin >> n;
	rep(i,n){
		cin >> a >> x >> y;
		if(a == 1){
			range[i] = mp(x,y);
			Rep(j,x,y){
				tempat[j].pb(i)
			}
		} else {
			memset(cek,-1,sizeof cek);
			udah = false;
			if(range[x].f > range[y].f){
				int tmp = x;
				x = y;
				y = x;
			}
			dfs(range[x].f,x);
			if(udah){
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		}
	}
}