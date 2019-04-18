#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,odd,even,first,second;
    cin >> n;
    cin >> a;
    odd = a;
    even = a;
    for(int i = 1;i<n;i++){
        cin >> a;
        first = a + odd;
        second = a + even;
        if((first % 2 == 0) && (first > even)){
            even = first;
        } else {
            if((first % 2 == 1) && (first > odd)){
                odd = first;
            }
        }
        if((second % 2 == 0) && (second > even)){
            even = second;
        } else {
            if((second % 2 == 1) && (second > odd)){
                odd = second;
            }
        }
        if(a % 2 == 0){
            even = max(even,a);
        } else {
            odd = max(odd,a);
        }
        cout << even << ' ' << odd << endl;
    }
    if(odd > 0){
        cout << odd;
    } else {
        cout << -1 << endl;
    }
}