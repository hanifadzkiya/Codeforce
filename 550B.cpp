#include <bits/stdc++.h>
using namespace std;

int n,l,r,k,data[20],sampai,sum,cnt,minimal,maksimal,x;
int main(){
	cin >> n >> l >> r >> x;
	for(int i = 1;i <= n;i++){
		cin >> data[i];
	}
	sampai = 1 << n;
	for(int i = 1;i<sampai;i++){
		maksimal = 0;
		minimal = 1000000000;
		sum = 0;
		for(int j = 1;j<=n;j++){
			if((i & (1 << (j-1)))){
				if(data[j] > maksimal) maksimal = data[j];
				if(data[j] < minimal) minimal = data[j];
				sum += data[j];				
			}
		}
		if((sum >= l && sum <= r) && (maksimal - minimal >= x)){
			cnt++;
		}
	}
	cout << cnt << endl;
}