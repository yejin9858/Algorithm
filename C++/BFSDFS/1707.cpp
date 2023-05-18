#include<iostream>
#include<vector>
#include<queue>
#include<string.h>

#define RED 1
#define BLUE -1

using namespace std;

vector<int> graph[20001];
int colored[20001];
int V, E;

void BFS(int start) {
	queue<int> q;

	int color = RED;
	colored[start] = color;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();

		if (colored[now] == RED) {
			color = BLUE;
		}
		else if (colored[now] == BLUE) {
			color = RED;
		}

		for (int node : graph[now]) {
			if (!colored[node]) {
				colored[node] = color;
				q.push(node);
			}
		}
		q.pop();

	}
}

void DFS(int start) {
	if (!colored[start]) {
		colored[start] = RED;
	}

	for (int node : graph[start]) {
		if (!colored[node]) {
			if (colored[start] == RED) {
				colored[node] = BLUE;
			}
			else if (colored[start] == BLUE) {
				colored[node] = RED;
			}
			DFS(node);
		}
	}
}

bool CheckBipartite() {
	for (int i = 1; i <= V; i++) {
		for (int node : graph[i]) {
			if (colored[i] == colored[node])
				return false;
		}
	}
	return true;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int K;
	cin >> K;
	while (K-- > 0) {
		bool bipartite = true;

		cin >> V >> E;

		for (int i = 0; i < E; i++) {
			int u, v;
			cin >> u >> v;

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			if (!colored[i])
				BFS(i);
				//DFS(i);
		}

		if (CheckBipartite()) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}

		
		for (int i = 1; i <= V; i++) {
			graph[i].clear();
		}
		memset(colored, 0, sizeof(colored));
	}
}