#include<iostream>
using namespace std;

int n;
int cows[20];
char let[20];

void cow_init_() {
	int i;
	for (i = 1; i <= n; i++) {
		cows[i] = i;
	}

}

//출력
void print() {
	int i;
	for (i = 1; i < n; i++) {
		printf("%d %c ", cows[i], let[i]);
	}
	printf("%d ", cows[n]);
}

void pullfront() {
	for (int i = 1; i < n; i++) {
		if (cows[i] == 0) {
			for (int j = i+1; j <= n; j++) {
				if (cows[j] != 0) {
					cows[i] = cows[j];
					cows[j] = 0;
					break;
				}
			}
		}
	}
}

//계산
int cal() {
	int hab=0, i, j=0;
	for (i = 1; i < n; i++) {
		if (let[i] == '.') {
			cows[i+1] = cows[i] * 10 + cows[i + 1];
			cows[i] = 0;
		}
		else {
			continue;
		}
	}

	pullfront();
	
	for (i = 1; i < n; i++) {
		if (j == 0) {
			if (let[i] == '+') {
				hab = cows[i] + cows[i + 1];
				j++;
			}
			else if (let[i] == '-') {
				hab = cows[i] - cows[i + 1];
				j++;
			}
		}
		else if (j > 0) {
			if (let[i] == '+') {
				hab = hab + cows[i + 1];
			}
			else if (let[i] == '-') {
				hab = hab - cows[i + 1];
			}
		}
	}
	cow_init_();
	print();
	printf(" : %d\n", hab);
	if (j > 0) {
		return hab;
	}
	else return 1;
}

void cow_chump(int pos) {
	if (pos==n) {
		if (cal() == 0) {
			print();
		}
	}
	else if (pos >= n) {
		return ;
	}
	else {
		let[pos] = '+';
		cow_chump(pos + 1);
		let[pos] = '-';
		cow_chump(pos + 1);
		let[pos] = '.';
		cow_chump(pos + 1);

	}
}

int main() {
	scanf("%d",&n);

	//소들 초기화
	cow_init_();
	cow_chump(1);
	return 0;
}