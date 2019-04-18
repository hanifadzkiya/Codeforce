#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n,cnt,case2,jawaban;
	cin >> n;
	cnt = 0;
	while(n >= 1000){
		cnt ++;
		n /= 10;
	}	
	case2 = 1;
	if(n > 99){
		if(n % 10 == 9){
			cnt++;
			n = n / 10;
			case2 = case2 * (n % 10);
			n = n / 10;
			case2 = case2 * (n % 10);
			if(case2 > 9){
				jawaban = 1;
				for(int i = 1;i<=cnt;i++){
					jawaban *= 9;
				}
				cout << case2*jawaban << endl;
			} else {
				jawaban = 1;
				for(int i = 1;i<=cnt+1;i++){
					jawaban *= 9;
				}
				cout << jawaban << endl;
			}
		} else {
			cnt++;
			n = n / 10;
			n--;
			case2 = case2 * (n % 10);
			n = n / 10;
			case2 = case2 * (n % 10);
			if(case2 > 9){
				jawaban = 1;
				for(int i = 1;i<=cnt;i++){
					jawaban *= 9;
				}
				cout << case2*jawaban << endl;
			} else {
				jawaban = 1;
				for(int i = 1;i<=cnt+1;i++){
					jawaban *= 9;
				}
				cout << jawaban << endl;
			}
		}
	} else if(n < 10) {
		cout << n << endl;
	} else {
		case2 = case2 * (n%10);
		n = n / 10;
		case2 = case2 * (n%10);
		if(9 > case2) case2 = 9;
		cout << case2 << endl;
	}
}