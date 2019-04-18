#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> data[300005];
priority_queue<long long, vector<long long>, greater<long long> >q;
long long n,k,a,b,jalan,hasil;
long long maksimal[300005];

bool pembanding(pair<long long,long long> x, pair<long long,long long> y){
	if(x.first == y.first){
		return x.second > y.second;
	} else return x.first < y.first;
}

int main(){
	cin >> n >> k;
	for(int i = 0;i<n;i++){
		cin >> a >> b;
		data[i] = make_pair(b,a);
	}
	sort(data,data+n,pembanding);
	maksimal[n] = 0;
	for(int i = n-1;i>=0;i--){
		//cout << data[i].second;
		if(n-i <= k){
			maksimal[i] = maksimal[i+1] + data[i].second;
			q.push(data[i].second);
		} else {
			maksimal[i] = 0;
			maksimal[i] -= q.top();
			maksimal[i] = maksimal[i] + maksimal[i+1] + data[i].second;
			q.pop();
			q.push(data[i].second);
		}
	}
	hasil = -1;
	for(int i = n-1;i>=0;i--){
		//cout << maksimal[i] << " " << data[i].first << endl;
		if(maksimal[i]*data[i].first > hasil){
			hasil = maksimal[i]*data[i].first;
		}
	}
	cout << hasil << endl;
}