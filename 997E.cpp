#include <bits/stdc++.h>
using namespace std;

map<long long,long long> hitung;
long long n,m,x,y,sum,parent[200005],ranked[200005],cnt[200005];
bool valid[200005];
int caribapak(int i){
	if(parent[i] == i){
		return i;
	} else {
		return parent[i] = caribapak(parent[i]); 
	}
}

void ufds(int i,int j){
	if(caribapak(i) != caribapak(j)){
		int x = caribapak(i);
		int y = caribapak(j);
		//cout << x << "a" << y << endl;
		if(ranked[x] > ranked[y])
			parent[y] = x;
		else {
			parent[x] = y;
			if(ranked[x] == ranked[y])
				ranked[y]++;
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		parent[i] = i;
		ranked[i] = 1;
		cnt[i] = 0;
		valid[i] = true;
	}
	for(int i = 0;i<m;i++){
		cin >> x >> y;
		cnt[x]++;
		cnt[y]++;
		ufds(x,y);
	}
	sum = 0;
	for(int i = 1;i<=n;i++){
		if(hitung.count(parent[i]) == 0){
			hitung[parent[i]] = 1;
		} else {
			hitung[parent[i]]++;
		}
		if(cnt[i] != 2){
			valid[parent[i]] = false;
		}
	}

	for (std::map<long long,long long>::iterator it=hitung.begin(); it!=hitung.end(); ++it){
		//cout << it->first << "-" << it->second << endl;
    	if(it->second >= 3 && valid[it->first]){
    		sum++;
    	}
    }
  //  cout << sum << endl;
    cout << sum << endl;
}