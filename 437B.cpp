#include <bits/stdc++.h>
using namespace std;

int sum,limit,cnt,last_significant;
bool data[100005];
int main(){
	cin >> sum >> limit;
  cnt = 0;
  memset(data,false,sizeof data);
  for(int i = limit;i>=1;i--){
    last_significant = i & (i*-1);
    // cout << i << " " << last_significant << endl;
    if(last_significant <= sum){
      sum -= last_significant;
      data[i] = true;
      cnt++;
    }
  }
  if(sum == 0){
    cout << cnt << endl;
    for(int i = 1;i<=limit;i++){
      if(data[i]) cout << i << " ";
    }
  } else {
    cout << -1 << endl;
  }
}