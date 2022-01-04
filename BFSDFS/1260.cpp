#include<iostream>
#include<string.h>
#include<queue>
using namespace std;

bool graph[1001][1001];
bool visit[1001];

int N, M, V; 
void DFS(int v);
void BFS(int v);
queue<int> q;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		graph[x][y] = true;
		graph[y][x] = true;
	}

	DFS(V);
	cout << "\n";
	memset(visit, false, sizeof(visit));
	BFS(V);
}

void DFS(int v) {
	cout << v << " ";
	visit[v] = true;
	for (int i = 1; i <= N; i++) {
		if (graph[v][i] && !visit[i]) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	q.push(v);
	visit[v] = true;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		for (int i = 1; i <= N; i++) {
			if (graph[v][i] && !visit[i]) {
				q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
		q.pop();
	}
}