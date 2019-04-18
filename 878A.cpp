#include <bits/stdc++.h>
using namespace std;

int n,num1,num2,jawab1,jawab2,jawab3,x;
char cmd;
int main(){
  cin >> n;
  num1 = 1023;
  num2 = 0;
  for(int i = 0;i<n;i++){
    cin >> cmd >> x;
    if(cmd == '&') {
      num1 = num1 & x;
      num2 = num2 & x;
    }
    if(cmd == '|'){
      num1 = num1 | x;
      num2 = num2 | x;
    } 
    if(cmd == '^'){
      num1 = num1 ^ x;
      num2 = num2 ^ x;
    }
    // cout << num1 << " " << num2 << endl;
  }
  // cout << num1 << " " << num2 << endl;
  cout << 3 << endl;
  jawab1 = 0;
  jawab2 = 0;
  jawab3 = 0;
  for(int i = 0;i<=9;i++){
    //dua duanya hidup
    if((num1 & (1 << i)) && (num2 & (1 << i))){
      jawab1 = jawab1 | (1 << i);
    } else if (((num1 & (1 << i)) || (num2 & (1 << i))) && (num2 & (1 << i))){
      jawab2 = jawab2 | (1 << i);
    } else {
      jawab3 = jawab3 | (1 << i);
    }
  }
  //cout << jawab2 << endl;
  for(int i = 0;i<=9;i++){
    jawab3 = jawab3 ^ (1 << i);
    if (((num1 & (1 << i)) || (num2 & (1 << i))) && (num1 & (1 << i))) jawab3 = jawab3 | (1 << i);
  }
  cout << "| " << jawab1 << endl;
  cout << "^ " << jawab2 << endl;
  cout << "& " << jawab3 << endl;
}
