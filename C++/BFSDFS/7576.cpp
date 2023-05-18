#include <queue>
#include <string>
#include <iostream>
using namespace std;

int box[1000][1000];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M, p, q, max = 0;
	queue<pair<int, int>> Q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> box[i][j];
			if (box[i][j] == 1) Q.push({ i,j });
		}
	}
	while (!Q.empty()) {
		p = Q.front().first;
		q = Q.front().second;
		for (int k = 0; k < 4; k++) {
			if (p + dx[k] >= 0 && q + dy[k] >= 0 && p + dx[k] < N && q + dy[k] < M && /*!visit[p + dx[k]][q + dy[k]] &&*/ box[p + dx[k]][q + dy[k]] != 1 && box[p + dx[k]][q + dy[k]] != -1)
			{
				if (box[p + dx[k]][q + dy[k]] > box[p][q] + 1 || !box[p + dx[k]][q + dy[k]]) {
					Q.push({ p + dx[k], q + dy[k] });
					box[p + dx[k]][q + dy[k]] = box[p][q] + 1;
				}
			}
		}
		Q.pop();
	}
	for (int n = 0; n < N; n++) {
		for (int m = 0; m < M; m++) {
			if (!box[n][m]) {
				cout << -1;
				return 0;
			}
			else if (max < box[n][m])
				max = box[n][m];
		}
	}
	cout << max-1;
}