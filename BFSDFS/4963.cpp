#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

int map[51][51];
bool visit[51][51];

int x[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int y[] = { 1, 1, 1, 0, 0, -1, -1, -1 };

int h, w;

int bfs() {

	queue<pair<int, int>> q;
	int ans = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (!visit[i][j] && map[i][j] == 1) {
				ans++;
				q.push({ i,j });
				visit[i][j] = true;
				do {
					int ix = q.front().first;
					int jy = q.front().second;
					for (int p = 0; p < 8; p++) {
						if (map[ix + x[p]][jy + y[p]] == 1 &&
							ix + x[p] >= 0 && ix + x[p] < h &&
							jy + y[p] >= 0 && jy + y[p] < w &&
							!visit[ix + x[p]][jy + y[p]]) {

							q.push({ ix + x[p],jy + y[p] });
							visit[ix + x[p]][jy + y[p]] = true;
						}
					}
					q.pop();
				} while (!q.empty());
			}
		}
	}

	return ans;
}

void dfs(int i , int j) {
	for (int p = 0; p < 8; p++) {
		if (map[i + x[p]][j + y[p]] == 1 &&
			i + x[p] >= 0 && i + x[p] < h &&
			j + y[p] >= 0 && j + y[p] < w &&
			!visit[i + x[p]][j + y[p]]) {

			visit[i + x[p]][j + y[p]] = true;
			dfs(i + x[p], j + y[p]);
		}
	}
	return;
}

int main(void) {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	while (true) {
		cin >> w >> h;

		if (!(h || w))
			return 0;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}

		//bfs
		cout << bfs() << "\n";

		//dfs
		/*int ans = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visit[i][j] && map[i][j] == 1) {
					dfs(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";*/

		memset(visit, false, sizeof(visit));
	}
	return 0;
}