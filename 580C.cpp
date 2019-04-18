#include <bits/stdc++.h>
using namespace std;

int n,m,cat[200005],dp[200005],a,b,sum;
vector<int> way[200005];

void depe(int idx,int parent){
	bool child = true;
	if(cat[parent] == 1)
		dp[idx] = dp[parent];
	else 
		dp[idx] = 0;
	dp[idx] += cat[idx];
	if(dp[idx] <= m){
		for(int i = 0;i<way[idx].size();i++){
			if(dp[way[idx][i]] == -1){
				depe(way[idx][i],idx);
				child = false;
			}
		}
		if(child){
			sum++;
		}
	} 
}

int main(){
	sum = 0;
	cin >> n >> m;
	for(int i= 0;i<n;i++){
		cin >> cat[i+1];
	}
	for(int i = 0;i<n-1;i++){
		cin >> a >> b;
		way[a].push_back(b);
		way[b].push_back(a);
	}
	memset(dp,-1,sizeof dp);
	dp[1] = cat[1];
	for(int i = 0;i<way[1].size();i++){
		depe(way[1][i],1);
	}
	cout << sum << endl;
}