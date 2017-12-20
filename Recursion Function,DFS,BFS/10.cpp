#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<vector<int>> gra;
vector<int> vis;

void bfs(int st) {
	vector<int> queue;
	int rear = 0, front = 0;

	queue.push_back(st);
	rear++;
	while (front < rear) {
		st = queue[front];
		for (int i = 0; i < gra[st].size(); i++) {
			if (vis[gra[st][i]] == 0) {
				vis[gra[st][i]] = 1;
				queue.push_back(gra[st][i]);
				rear++;
			}
		}
		front++;
	}
	printf("%d", rear - 1);

}

int main() {
	int a, b;
	scanf("%d",&n);
	gra.resize(n + 1);
	vis.resize(n + 1);
	scanf("%d",&m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d",&a,&b);
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	//Á¤·Ä
	for (int i = 0; i < n; i++) {
		sort(gra[i].begin(), gra[i].end());
	}

	vis[1] = 1;
	bfs(1);
	printf("\n");
	return 0;

}