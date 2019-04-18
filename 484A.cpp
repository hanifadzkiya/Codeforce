#include <bits/stdc++.h>
using namespace std;

long long l,r;
int n;

long long duapangkat(long long x){
  long long ans = 1;
  x /= 2;
  while(x > 0){
    ans *= 2;
    x /= 2;
  }
  return ans;
}

long long ans(long long l, long long r){
  long long dua;
  if(l == r) return r;
  dua = duapangkat(r);
  if(dua <= l) return ans(l-dua,r-dua) + dua;
  if(dua*2-1 <= r) return dua*2-1;
  return dua-1;
}

int main(){
	cin >> n;
	while(n--){
		cin >> l >> r;
		cout << ans(l,r) << endl;
	}
}