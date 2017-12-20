#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int > > gra;
vector<int> visit;
vector<int> visit2;

void dfs(int st) {
	for (int i = 0; i < gra[st].size(); i++) {
		if (visit[gra[st][i]] == 0) {
			visit[gra[st][i]] = 1;
			printf("%c", gra[st][i]+'A');
			dfs(gra[st][i]);
		}
	}
}

void bfs(int st) {
	vector<int> queue;
	int rear = 0, front = 0;

	queue.push_back(st);
	rear++;
	while (front < rear) {
		st = queue[front];
		for (int i = 0; i < gra[st].size(); i++) {
			if(visit2[gra[st][i]]==0){
				visit2[gra[st][i]] = 1;
				queue.push_back(gra[st][i]);
				rear++;
			}
		}
		front++;
	}
	for (int i = 0; i < rear; i++) {
		printf("%c",queue[i]+'A');
	}

}

 int main() {
	char st;
	char a, b;

	scanf("%d %d", &n, &m);

	gra.resize(n);
	visit.resize(n);
	visit2.resize(n);

	//입력
	for (int i = 0; i < m; i++) {
		scanf(" %c %c",&a,&b);
		gra[a - 'A'].push_back(b - 'A');
	}

	//정렬
	for (int i = 0; i < n; i++) {
		sort(gra[i].begin(),gra[i].end());
	}

	scanf(" %c",&st);
	visit[st - 'A'] = 1;
	printf("%c", st);

	dfs(st - 'A');
	printf("\n");

	bfs(st - 'A');

	return 0;
}