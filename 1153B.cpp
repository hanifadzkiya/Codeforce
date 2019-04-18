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
pair<int,int> datam[105],datan[105];
int datamis[105],datanis[105],datak[105][105],n,m,k;
bool pembanding(pair<int,int> x,pair<int,int> y){
	return x.s < y.s;
}

int main(){
	cin >> n >> m >> k;
	rep(i,m){
		cin >> datamis[i];
		datam[i] = mp(i,datamis[i]);
	}
	rep(i,n){
		cin >> datanis[i];
		datan[i] = mp(i,datanis[i]);
	}
	rep(i,n){
		rep(j,m){
			cin >> datak[i][j];
		}
	}
	rep(i,m){
		rep(j,n){
			// cout << i << " " << datamis[i] << " " << j << " " << datanis[j] << " " << datak[i][j] << endl;
			if(datak[j][i] == 1 && datamis[i] <= datanis[j] && datamis[i] != 0){
				// cout << "Masuk" << endl;
				datak[j][i] = datamis[i];
			}
		}
	}
	// rep(i,n){
	// 	rep(j,m){
	// 		cout << datak[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	rep(i,n){
		rep(j,m){
			// cout << i << " " << datamis[i] << " " << j << " " << datanis[j] << " " << datak[i][j] << endl;
			if(datak[i][j] == 1 && datanis[i] <= datamis[j] && datanis[i] != 0){
				// cout << "Masuk" << endl;
				datak[i][j] = datanis[i];
			}
		}
	}
	rep(i,n){
		cout << datak[i][0];
		Rep(j,1,m-1){
			cout << " " << datak[i][j] ;
		}
		cout << endl;
	}
	// sort(datam,datam+m,pembanding);
	// repr(i,m){
	// 	cout << datam[i].f << " " << datam[i].s << endl;
	// 	rep(j,n){
	// 		if(datak[j][datam[i].f] == 1 && datanis[j] < datam[i].s){
	// 			datak[j][datam[i].f] = datam[i].s;
	// 		}
	// 	}
	// }
	// rep(i,n){
	// 	cout << datak[i][0];
	// 	Rep(j,1,m-1){
	// 		cout << " " << datak[i][j];
	// 	}
	// 	cout << endl;
	// }
	// sort(datan,datan+n,pembanding);
	// repr(i,n){
	// 	rep(j,m){
	// 		if(datak[datan[i].f][j] == 1 && datamis[j] < datan[i].s){
	// 			datak[datan[i].f][j] = datan[i].s;
	// 		}
	// 	}
	// }
	// rep(i,n){
	// 	cout << datak[i][0];
	// 	Rep(j,1,m-1){
	// 		cout << " " << datak[i][j];
	// 	}
	// 	cout << endl;
	// }
}