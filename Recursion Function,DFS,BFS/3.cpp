#include<iostream>
using namespace std;

int n, k, a[500], cnt = 0;

void f(int len, int one) {
	if (len == n && one == k) {
		for (int i = 0; i <len; i++) {
			cout << a[i];
		}
		cout << endl;
		return;
	}
	else if (len == n && one != k) {
		return;
	}
	else if (one > k) return;
	else if (len < n) {
		a[len] = 1;
		f(len + 1, one + 1);
		a[len] = 0;
		f(len + 1, one);
	}
}

int main() {

	int i, j;
	cin >> n;
	cin >> k;
	f(0, 0);

	return 0;	
}