#include <bits/stdc++.h>
using namespace std;

long long sampai,n,len,cnt;
map<long long,bool> udah;
long long banyakDigit(long long n){
  long long cnt;
  cnt = 0;
  while(n > 0){
    n /= 10;
    cnt++;
  }
  return cnt;
}

bool isCan(long long a,long long n,long long x,long long y){
  long long sum;
  sum = 0;
  while(a > 0){
    sum *= 10;
    if(a % 2 == 1){
      sum += x;
    } else {
      sum += y;
    }
    a /= 2;
  }
  if(udah.count(sum) != 0){
    return false;
  }
  if(sum == 0) return false;
  udah[sum] = true;
  return(sum <= n);
}

int main(){
  cin >> n;
  len = banyakDigit(n);
  sampai = 1 << len;
  cnt = 0;
  for(int i = 1;i<sampai;i++){
    for(int j = 0;j<=9;j++){
      for(int k = 0;k<=9;k++){
        if(isCan(i,n,k,j)) cnt++;
      }
    }
  }
  cout << cnt << endl;
}