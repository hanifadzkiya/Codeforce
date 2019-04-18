#include <bits/stdc++.h>
using namespace std;

int n,m,tmp,idx,sama,res,maksimal,sampai,bad[200],banyakdigit;
bool gagal;
string data[20],a,b;
vector<string> hasil;
map<string,int> indexed;

int main(){
	cin >> n >> m;
  for(int i = 1;i<=n;i++){
    cin >> data[i];
    indexed[data[i]] = i;
  }
  for(int i = 0;i<m;i++){
    cin >> a >> b;
    bad[i] = 0;
    bad[i] = bad[i] | (1 << (indexed[a] - 1));
    bad[i] = bad[i] | (1 << (indexed[b] - 1));
  }
  sampai = 1 << n;
  for(int i = 1;i<sampai;i++){
    //cout << i << endl;
    gagal = false;
    for(int j = 0;j<m;j++){
      tmp = bad[j];
      //cout << tmp << endl;
      idx = 1;
      sama = 0;
      while(tmp > 0){
        if(tmp % 2 == 1){
          if((i & (1 << (idx-1)))){
            sama++;
          }
        }
        idx++;
        tmp /= 2;
      }
      if(sama == 2){
        //cout << 'j';
        gagal = true;
      }
    }
    if(!gagal){
      banyakdigit = 0;
      res = i;
      while(res > 0){
        banyakdigit += res % 2;
        res /= 2;
      }
      if(banyakdigit > maksimal){
        hasil.clear();
        maksimal = banyakdigit;
        res = i;
        idx = 1;
        while(res > 0){
          if(res % 2 == 1){
            hasil.push_back(data[idx]);
          }
          idx++;
          res /= 2;
        }
      }
    }
  }
  cout << maksimal << endl;
  sort(hasil.begin(),hasil.end());
  for(int i = 0;i<maksimal;i++){
    cout << hasil[i] << endl;
  }
}