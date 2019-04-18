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

int dp[100005],n,sum,x,y;
vector<int> edge[100005];
void dfs(int idx,int p){
	dp[idx] = 1;
	rep(i,edge[idx].size()){
		if(edge[idx][i] != p){
			dfs(edge[idx][i],idx);
			if(dp[edge[idx][i]] % 2 == 0){
				sum++;
			}
			dp[idx] += dp[edge[idx][i]];
		}
	}
}

int main(){
	cin >> n;
	Rep(i,0,n-2){
		cin >> x >> y;
		edge[x].pb(y);
		edge[y].pb(x);
	}
	sum = 0;
	dfs(1,0);
	if(n % 2 == 0){
		cout << sum << endl;
	} else {
		cout << -1 << endl;
	}
}