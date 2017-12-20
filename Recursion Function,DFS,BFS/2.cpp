#include<stdio.h>

int result[11000000], tmp = 0, middle = 0;

void binaryTree(int n) {
	if (n == 1) {
		result[tmp++] = n;
	}
	else{
		binaryTree(n - 1);
		result[tmp++] = n;
		if (n != middle)
			binaryTree(n - 1);
	}
}

int main() {
	int n, i;

	scanf("%d",&n);

	middle = n;
	binaryTree(n);

	for (i = 0; i < tmp; i++) {
		printf("%d",result[i]);
	}
	for (i = tmp-2; i >=0 ; i--) {
		printf("%d", result[i]);
	}
	printf("\n");

	return 0;
}