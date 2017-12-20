#include<iostream>
#include<stdio.h>
using namespace std;

int n;
int flag = 0;
char k[11];
int answer[12];
int visit[12] = {0,};

//
void search_front(int w) {
	if (w==n+1) {
		for (int i = 0; i < w; i++) {
			printf("%d",answer[i]);
		}
		printf("\n");
		flag = 1;
		return;
	}
	else if (k[w-1]=='<' && answer[w-1]!=9) {
		for (int i = answer[w-1]; i <= 9; i++) {
			if (visit[i] == 0) {
				answer[w] = i;
				visit[i] = 1;
				search_front(w + 1);
				visit[i] = 0;
				if (flag == 1) return;
			}
		}
	}
	else if (k[w - 1] == '>') {
		for (int i = answer[w - 1]; i >= 0; i--) {
			if (visit[i] == 0) {
				answer[w] = i;
				visit[i] = 1;
				search_front(w + 1);
				visit[i] = 0;
				if (flag == 1) return;
			}
		}
	}
	else if(w==0){
		for (int i = 9; i >= 0; i--) {
			answer[w] = i;
			visit[i] = 1;
			search_front(w + 1);
			visit[i] = 0;
			if (flag == 1) return;
		}
	}
}

void search_back(int w) {
	if (w == n + 1) {
		for (int i = 0; i < w; i++) {
			printf("%d", answer[i]);
		}
		printf("\n");
		flag = 1;
		return;
	}
	else if (k[w - 1] == '<' && answer[w - 1] != 9) {
		for (int i = answer[w - 1]; i <= 9; i++) {
			if (visit[i] == 0) {
				answer[w] = i;
				visit[i] = 1;
				search_back(w + 1);
				visit[i] = 0;
				if (flag == 1) return;
			}
		}
	}
	else if (k[w - 1] == '>' && answer[w-1]!=0) {
		for (int i = answer[w - 1]; i >= 0; i--) {
			if (visit[i] == 0) {
				answer[w] = i;
				visit[i] = 1;
				search_back(w + 1);
				visit[i] = 0;
				if (flag == 1) return;
			}
		}
	}
	else if (w == 0) {
		for (int i = 0; i <= 9; i++) {
			answer[w] = i;
			visit[i] = 1;
			search_back(w + 1);
			visit[i] = 0;
			if (flag == 1) return;
		}
	}
}

int main() {
	int i;
	scanf("%d",&n);
	for (i = 0; i < n; i++) {
		scanf("%s",&k[i]);
	}
	search_front(0);
	flag = 0;
	search_back(0);
	return 0;
}