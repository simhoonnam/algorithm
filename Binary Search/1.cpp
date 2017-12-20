#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, me, pos;
vector<int> box;
vector<int> card;
vector<int> check;

 void binary_search(int front, int middle, int back) {
	if (card[front] == me || card[middle] == me || card[back] == me) {
		check[pos] = 1;
		return;
	}
	else if(front>=back){
		check[pos] = 0;
		return;
	}
	else if(card[middle]>me){
		binary_search(front, middle / 2, middle);
	}
	else if (card[middle] < me) {
		binary_search(middle+1, (middle + back) / 2, back);
	}

}

int main() {

	//손패 카드 입력
	scanf("%d", &n);
	card.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &card[i]);
	sort(card.begin(), card.begin() + n);
	
	//박스 입력
	scanf("%d",&m);
	box.resize(m);
	check.resize(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &box[i]);
	}

	for (int i = 0; i < m; i++) {
		me = box[i];
		pos = i;
		binary_search(0, n / 2, n-1);
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n",check[i]);
	}
	
	return 0;
}