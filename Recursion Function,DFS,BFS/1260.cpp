#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int>> gra;
vector<int> visit;
vector<int> visit2;

void dfs(int st) {
	for (int i = 0; i < gra[st].size(); i++) {
		if (visit[gra[st][i]] == 0) {
			visit[gra[st][i]] = 1;
			printf("%d ", gra[st][i]);
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
			if (visit2[gra[st][i]] == 0) {
				visit2[gra[st][i]] = 1;
				queue.push_back(gra[st][i]);
				rear++;
			}
		}
		front++;
	}
	for (int i = 0; i < rear; i++) {
		printf("%d ", queue[i]);
	}

}

int main() {
	int st;
	int a, b;

	scanf("%d %d", &n, &m);
	scanf(" %d", &st);

	gra.resize(n+1);
	visit.resize(n+1);
	visit2.resize(n+1);

	//입력
	for (int i = 0; i < m; i++) {
		scanf(" %d %d", &a, &b);
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	//정렬
	for (int i = 0; i < n; i++) {
		sort(gra[i].begin(), gra[i].end());
	}

	visit[st] = 1;
	printf("%d ", st);

	dfs(st);
	printf("\n");

	visit2[st] = 1;
	bfs(st);
	printf("\n");

	return 0;
}