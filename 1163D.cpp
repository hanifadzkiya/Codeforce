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

int n,isChild[300005],x;
int minmaxs[300005],jmlanak;
vector<int> child[300005];
int dfs(int idx){
	int tmp = 0;
	if(child[idx].size() == 0){
		return 0;
	}
	rep(i,child[idx].size()){
		if(isChild[child[idx][i]] == -1){
			tmp++;
		}
	}
//	cout << tmp << endl;
	int calon = -1;
	if(tmp > 0 && minmaxs[idx] == 0){
		calon = jmlanak-tmp+1;
	} else {
		if(tmp > 0 && minmaxs[idx] == 1)calon = jmlanak;
	}
//	cout << calon << " " << idx << endl;
	int cal;
	if(minmaxs[idx] == 0){
		cal = 999999;
	} else {
		cal = -1;
	}
	rep(i,child[idx].size()){
		if(isChild[child[idx][i]] != -1){
			if(minmaxs[idx] == 0){
				cal = min(cal,dfs(child[idx][i]));
			} else {
				cal = max(cal,dfs(child[idx][i]));
			}
		}
	}
	// cout << calon << " " << cal << " " << idx << endl;
	if(minmaxs[idx] == 0){
		if(calon != -1)
			return min(calon,cal);
		return cal;
	} else {
		if(calon != -1)
			return max(calon,cal);
		return cal;
	}
}

int main(){
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> minmaxs[i];
	}
	memset(isChild,-1,sizeof isChild);
	jmlanak = n;
	for(int i = 2;i<=n;i++){
		cin >> x;
		if(isChild[x] == -1){
			jmlanak--;
		}
		isChild[x] = 0;
		child[x].pb(i);
	}
	cout << dfs(1) << endl;
}