#include<iostream>
#include<algorithm>
using namespace std;
char danji[30][30] = { 'A', };
int danji_howmuch[30];
int cnt=0;

void danji_cnt(int x , int y) {
	if (danji[x][y] == '0') {
		return;
	}
	else if (danji[x][y] == '1') {
		cnt++;
		danji[x][y] = '0';
		danji_cnt(x - 1, y);
		danji_cnt(x, y - 1);
		danji_cnt(x + 1, y);
		danji_cnt(x, y + 1);
	}
}

int main() {
	int n;
	int ww = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> danji[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt = 0;
			danji_cnt(i, j);
			if (cnt != 0) danji_howmuch[ww++] = cnt;
		}
	}
	cout << ww << endl;
	sort(danji_howmuch, danji_howmuch + ww);
	for (int i = 0; i < ww; i++) {
		cout << danji_howmuch[i] << endl;
	}
	return 0;
}