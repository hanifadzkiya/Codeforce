#include <bits/stdc++.h>
using namespace std;

int n,k,mulai,cnt,data[100005];
int cek[100005];

int main(){
  cin >> n >> k;
  for(int i = 0;i<n;i++){
    cin >> data[i];
  }
  memset(cek,0,sizeof cek);
  mulai = 0;
  cnt = 0;
  while(mulai < (n-1) && data[mulai] == data[mulai+1]) mulai++;
  for(int i = mulai;i<n;i++){
    if(cek[data[i]] == 0){
      cnt++;
    }
    cek[data[i]]++;
    if(cnt == k){
      while(cek[data[mulai]] > 1){
        cek[data[mulai]]--;
        mulai++;
      }
      cout << mulai+1 << " " << i+1 << endl;
      return 0;
    }
  } 
  cout << -1 << " " << -1 << endl;
}