#include<iostream>
using namespace std;

int n, a[5050], cnt = 0;

void f(int len,int value) {
	int i;
	if(value==n){
		for (i = 0; i < len; i++) {
			if (a[i] < a[i + 1]) return;
		}
		for (i = 0; i < len; i++) {
			cout << a[i];
			if (i != len - 1) cout << "+";
		}
		cout << endl;
		cnt++;
	}
	else if (value > n) return;
	else {
		for (i = n - 1; i >= 1; i--) {
			a[len] = i;
			f(len + 1, value + i);
		}
	}
}

int main() {

	cin >> n;

	f(0,0);

	cout << cnt << endl;

	return 0;
}