#include <bits/stdc++.h>
using namespace std;

int main(){
	int tc,x,maksb,maksa;
	string s;
	cin >> tc;
	while(tc--){
		cin >> x;
		cin >> s;
		if(s[0] == '>' || s[x-1] == '<'){
			cout << 0 << endl;
		} else {
			maksa = -1;
			maksb = x-2;
			for(int i = 0;i<x;i++){
				if(s[i] == '<'){
					maksa = i;
				}
			}
			for(int i = x-1;i>=0;i--){
				if(s[i] == '>'){
					maksb = i;
				}
			}
			cout << min(x-maksa-1,maksb) << endl;
		}
	}
}