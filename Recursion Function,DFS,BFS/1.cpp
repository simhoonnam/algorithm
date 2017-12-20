#include<stdio.h>

int result[15], cnt=0;

int BinarySearch(int a) {
	if (a / 2 == 0) {
		result[cnt] = a;
	}
	else {
		result[cnt++] = a % 2;
		return BinarySearch(a / 2);
	}
}

int main() {
	int n, i;

	scanf("%d",&n);

	BinarySearch(n);

	for (i = cnt; i >= 0; i--) {
		printf("%d",result[i]);
	}
	printf("\n");

	return 0;
}