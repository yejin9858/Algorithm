#include <queue>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int map[100][100];
bool visit[100][100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	queue<pair<int, int>> Q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int N, min = 200, p, q, x, y, land = 1, size, result = 0;
	bool clear = false;
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1 && !visit[i][j]) {
				land++;
				Q.push({ i,j });
				map[i][j] = land;
				visit[i][j] = true;
				while (!Q.empty()) {
					p = Q.front().first;
					q = Q.front().second;
					for (int i = 0; i < 4; i++) {
						x = p + dx[i];
						y = q + dy[i];
						if (x >= 0 && y >= 0 && x < N && y < N) {
							if (map[x][y] == 1) {
								map[x][y] = land;
								Q.push({ x,y });
								visit[x][y] = true;
							}
						}
					}
					Q.pop();
				}
				memset(visit, false, sizeof(visit));
			}
		}
	}
	for (int l = 2; l < land; l++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (l == map[i][j]) {
					Q.push({ i,j });
				}
			}
		}
		while (!Q.empty()) {
			size = Q.size();
			while (size--) {
				p = Q.front().first;
				q = Q.front().second;
				for (int i = 0; i < 4; i++) {
					x = p + dx[i];
					y = q + dy[i];
					if (x >= 0 && y >= 0 && x < N && y < N && !visit[x][y]) {
						if (!map[x][y]) {
							Q.push({ x,y });
							visit[x][y] = true;
						}
						else if (map[x][y] != l && result < min) {
							min = result;
							clear = true;
							size = 0;
						}
					}
				}
				Q.pop();
				if (clear) {
					while (!Q.empty())
						Q.pop();
					clear = false;
				}
			}
			result++;
		}
		result = 0;
		memset(visit, false, sizeof(visit));
	}
	cout << min;
}