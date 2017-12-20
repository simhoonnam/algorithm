#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int a, b, v;
	int pos = 0, day = 1;

	scanf("%d %d %d",&a,&b,&v);

	v -= a;
	day += v / (a - b);
	if (v % (a - b) != 0) {
		day++;
	}

	printf("%d\n", day);
	return 0;
}