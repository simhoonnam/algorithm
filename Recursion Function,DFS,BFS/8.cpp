#include<iostream>
using namespace std;

int n,fin=0;
int good[100];

int compare(int len) {
	int a;
	int cnt;
	if (len % 2 == 0) a = len / 2;
	else a = (len / 2) + 1;
	for (int i = 1; i <= a; i++) {
		cnt = 0;
		for (int j = 0; j < i; j++) {
			if (good[len - j] == good[len - j - i]) {
				cnt++;
			}
		}
		if (cnt == i) {
			return 0;
		}
	}
	return 1;
}

void check(int x) {
	if (fin == 1) {
		return;
	}
	else if (x == n && fin==0) {
		for (int i = 0; i < n; i++) {
			cout << good[i];
		}
		cout << endl;
		fin = 1;
		return;
	}
	else{
		for (int i = 1; i <= 3; i++) {
			good[x] = i;
			if (compare(x)) {
				check(x + 1);
			}
		}
	}

}
int main() {
	cin >> n;
	check(0);
	return 0;
}