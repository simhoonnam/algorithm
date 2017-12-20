#include<stdio.h>
#include<vector>

using namespace std;

long long int n, m, h, max_;
long long int this_is_dab = 0;
vector<long long int> tree;

void parametric_search( long long int front, long long int middle, long long int end) {
	long long int hab = 0;
	for (int i = 0; i < n; i++) {
		if(tree[i]-middle>0)
			hab += tree[i] - middle;
	}
	//µü ¸Â¾Æ ¶³¾îÁú¶§
	if (hab>=m) {
		this_is_dab = middle;
	}
	
	if(front>=end) {
		return;
	}
	else if (hab > m) {
		parametric_search(middle+1, (middle+1 + end) / 2, end);
	}else if (hab < m) {
		parametric_search(front, (front+middle-1) / 2, middle-1);
	}
}

int main() {
	scanf("%d %d",&n,&m);
	tree.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tree[i]);
		if (tree[i] > max_) {
			max_ = tree[i];
		}
	}
	parametric_search(0, max_ / 2, max_);
	printf("%d\n",this_is_dab);
	return 0;
}