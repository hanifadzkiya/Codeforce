#include <bits/stdc++.h>
using namespace std;

map<long long,long long> hitung;
long long n,m,x,y,sum,parent[150005],ranked[150005];
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
	for(int i = 0;i<=n;i++){
		parent[i] = i;
		ranked[i] = 1;
	}
	for(int i = 0;i<m;i++){
		cin >> x >> y;
		ufds(x,y);
	}
	sum = 0;
	for(int i = 1;i<=n;i++){
		//cout << i << " " << parent[i] << endl;
		if(hitung.count(parent[i]) == 0){
			hitung[parent[i]] = 1;
		} else {
			hitung[parent[i]]++;
		}
	}
	for (std::map<long long,long long>::iterator it=hitung.begin(); it!=hitung.end(); ++it)
    	sum += it->second*(it->second-1)/2;
  //  cout << sum << endl;
    if(sum == m){
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
}