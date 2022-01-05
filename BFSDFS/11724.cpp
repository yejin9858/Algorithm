#include<iostream>
#include<queue>
using namespace std;

int graph[1001][1001];
bool visit[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int M, N;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u][v] = true;
		graph[v][u] = true;
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		if (!visit[i]) {
			ans++;
			queue<int> q;
			q.push(i);
			visit[i] = true;
			int now;
			while (!q.empty()) {
				now = q.front();
				for (int j = 1; j <= N; j++) {
					if (!visit[j] && graph[now][j]) {
						q.push(j);
						visit[j] = true;
					}
				}
				q.pop();
			}
		}
	}

	cout << ans;
	return 0;
}