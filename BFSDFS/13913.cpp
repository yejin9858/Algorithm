#include<iostream>
#include<queue>
#include<stack>

#define MAX 100001
using namespace std;

int parent[MAX];
bool visit[MAX];
stack<int> path;

int N, K;

void termination() {
	int idx = K;
	while (idx != N) {
		path.push(idx);
		idx = parent[idx];
	}
	path.push(N);
	return;
}

int bfs() {

	queue<pair <int, int>> q;

	q.push({ N,0 });
	visit[N] = true;

	while (!q.empty()) {

		int now = q.front().first;
		int sec = q.front().second;

		if (now * 2 < MAX && !visit[now * 2])
		{
			q.push({ now * 2, sec + 1 });
			visit[now * 2] = true;
			parent[now * 2] = now;
			if (now * 2 == K) {
				termination();
				return sec + 1;
			}
		}
		if (now + 1 < MAX && !visit[now + 1])
		{
			q.push({ now + 1, sec + 1 });
			visit[now + 1] = true;
			parent[now + 1] = now;
			if (now + 1 == K) {
				termination();
				return sec + 1;
			}
		}

		if (now - 1 >= 0 && !visit[now - 1])
		{
			q.push({ now - 1, sec + 1 });
			visit[now - 1] = true;
			parent[now - 1] = now;
			if (now - 1 == K) {
				termination();
				return sec + 1;
			}
		}

		q.pop();
	}
}

int main(void) {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> K;

	if (N == K) {
		cout << "0\n" << N;
		return 0;
	}
	else if (N > K) {
		cout << N - K << "\n";
		for (int i = N; i >= K; i--) {
			cout << i << " ";
		}
		return 0;
	}
	cout << bfs() << "\n";

	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}

	return 0;
}