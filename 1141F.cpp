#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int n,data[1505],sum[1505],maksimal,hasil,cnt,akhir;;
map<int,vector<pair<int, int> > > cek;

bool pembanding(pair<int, int> x,pair<int, int> y){
	return x.second < y.second;
}

int main(){
	cin >> n;
	sum[0] = 0;
	for(int i = 1;i<=n;i++){
		cin >> data[i];
		sum[i] = sum[i-1] + data[i];
	}
	for(int i = 0;i<n;i++){
		for(int j = i+1;j<=n;j++){
			cek[sum[j] - sum[i]].push_back(mp(i+1,j));
		}
	}
	maksimal = 0;
	hasil = 0;
	for(map<int,vector<pair<int, int> > >::iterator it = cek.begin();it != cek.end();it++){
		sort(it->second.begin(),it->second.end(),pembanding);
		cnt = 0;
		akhir = 0;
		for(int i = 0;i<it->second.size();i++){
			if(it->second[i].first > akhir){
				akhir = it->second[i].second;
				cnt++;
			}
		}
		if(cnt > maksimal){
			maksimal = cnt;
			hasil = it->first;
		}
	}
	cout << maksimal << endl;
	akhir = 0;
	for(int i = 0;i< cek[hasil].size();i++){
		if(cek[hasil][i].first > akhir){
			cout << cek[hasil][i].first << " " << cek[hasil][i].second << endl;
			akhir = cek[hasil][i].second;
		}
	}
}