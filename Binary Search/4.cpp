#include<stdio.h>
#include<vector>

using namespace std;

long long int n, m, k, cnt = 0, dab = 0;

void NN_search(long long int front, long long int middle, long long int end) {
	long long int i=1;
	cnt = 0;
	while (i<=n) {
		if (i*n<middle) {
			cnt += n;
		}
		else if (i*n >= middle) {
			cnt += middle / i;
		}
		i++;
	}
	if (front>=middle) {
		printf("%d\n", dab);
		return;
	}
	else if (cnt <= m) {
		dab = middle;
		NN_search(middle, (middle + end) / 2, end);
	}
	else if (cnt > m) {
		dab = middle;
		NN_search(front, (front + middle) / 2, middle);
	}
}

int main() {
	long long int mid_;
	scanf("%d %d", &n, &m);
	mid_ = (1 + n*n) / 2;
	NN_search(1, mid_, n*n);
	return 0;
}

