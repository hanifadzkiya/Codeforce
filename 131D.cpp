#include <bits/stdc++.h>
using namespace std;
#define pb push_back
bool lewat[3005];
vector<int> way[3005];
int n,x,y,tes,jarak[3005];

void isiJarak(int idx,int cnt,int parent){
	cout << idx << " " << cnt << " " << parent << endl;
	jarak[idx] = cnt;
	for(int i = 0;i<way[idx].size();i++){
		if(way[idx][i] != parent && !lewat[way[idx][i]]){
			isiJarak(way[idx][i],cnt+1,idx);
		}
	}
}

void dfs(int idx,int parent){
	// cout << idx << " " << parent << endl;
	tes++;
	if(lewat[idx] && parent != 0){
		// cout << idx << "-" << parent << endl;
		for(int i = 1;i<=n;i++){
			if(lewat[i]){
				isiJarak(i,0,i);
			}
		}
	} else {
		// cout << idx << "+" << parent << endl;
		lewat[idx] = true;
		for(int i = 0;i<way[idx].size();i++){
			if(way[idx][i] != parent){
				dfs(way[idx][i],idx);
			}
		}
		lewat[idx] = false;
 	}
}

int main(){
	tes = 0;
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> x >> y;
		way[x].pb(y);
		way[y].pb(x);
		lewat[i] = false;
		jarak[i] = 0;
	}
	lewat[n]= false;
	jarak[n] = false;
	lewat[1] = true;
	dfs(1,0);
	cout << jarak[1];
	for(int i = 2;i<=n;i++){
		cout << " " << jarak[i];
	}
	cout << endl;
}