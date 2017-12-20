#include<stdio.h>
/*
-1Àº +
-2´Â -
-3Àº .
*/

int n;
long long int cows[100];
int cnt_hab = 0;

void cow_init_() {
	int i, cnt = 1;
	int N = (n - 1) * 2;
	for (i = 0; i <= N; i+=2) {
		cows[i] = cnt++;
	}
}

int cal() {
	int i, j, k;
	int hab = 0;
	for(i=1;i<n * 2 + 1;i+=2){
		if (cows[i] == -3) {
			if(cows[i+1]<10)
				cows[i + 1] = cows[i - 1] * 10 + cows[i + 1];
			else if(cows[i+1]>=10)
				cows[i + 1] = cows[i - 1] * 100 + cows[i + 1];
			cows[i - 1] = 0;
		}
	}
	for (k = 0; k <= n * 2 + 1; k++) {
		if (cows[k] > 0) {
			hab = cows[k];
			break;
		}
	}
	for (i = k+1; i < n * 2 + 1; i++) {
		if (cows[i] < 0) {
			for (j = i + 1; j < n*2+1; j++) {
				if (cows[j] > 0) {
					break;
				}
			}

			switch (cows[i]) {
			case -1:
				hab += cows[j];
				break;
			case -2:
				hab -= cows[j];
				break;
			}
		}
	}
	cow_init_();
	return hab;
}

void print() {
	for (int i = 0; i < n * 2 + 1; i++) {
		if (cows[i] > 0) printf("%lld ",cows[i]);
		else if (cows[i] == -1) printf("+ ");
		else if (cows[i] == -2) printf("- ");
		else if (cows[i] == -3) printf(". ");
	}
	printf("\n");
}

void cow_chump(int pos) {
	int tmp;
	if (pos == n*2-1) {
		tmp = cal();
		if (tmp == 0) {
			if (cnt_hab < 20) {
				print();
			}
			cnt_hab++;
		}
	}
	else if (pos > n * 2 - 1) {
		return;
	}
	else {
		cows[pos] = -1;
		cow_chump(pos + 2);
		cows[pos] = -2;
		cow_chump(pos + 2);
		cows[pos] = -3;
		cow_chump(pos + 2);

	}
}

int main() {
	scanf("%d",&n);

	cow_init_();
	cow_chump(1);
	printf("%d\n", cnt_hab);
	return 0;
}