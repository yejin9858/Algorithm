#include <queue>
#include <string>
#include <iostream>
using namespace std;

int canvas[100][100];
bool visit[100][100];
int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	int N, M, p, q, num = 2;
	queue<pair<int, int>> Q;
	string str;
	bool done = false;
	cin >> N >> M;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	for (int i = 0; i < N; i++) {
		cin >> str;
		int j = 0;
		for (int n : str)
			canvas[i][j++] = n - 48;
	}
	p = 0; q = 0;
	Q.push({ 0,0 });
	visit[0][0] = true;
	do {
		p = Q.front().first;
		q = Q.front().second;
		for (int k = 0; k < 4; k++) {
			if (p + dx[k] >= 0 && q + dy[k] >= 0 && p + dx[k] < N && q + dy[k] < M) {
				if (canvas[p + dx[k]][q + dy[k]] != 0 && !visit[p + dx[k]][q + dy[k]]) {
					Q.push({ p + dx[k], q + dy[k] });
					visit[p + dx[k]][q + dy[k]] = true;
					canvas[p + dx[k]][q + dy[k]] = canvas[p][q] + 1;
					done = true;
				}
			}
		}
		if (done)
			num++;
		done = false;
		Q.pop();
	} while (!Q.empty());
	cout << canvas[N - 1][M - 1];
}