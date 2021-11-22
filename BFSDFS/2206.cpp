#include <queue>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int visit[1000][1001][2];
char maze[1000][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, M, p = 0, q = 0, r = 0, x, y, size, far = 0;
	bool clear = false;
	string str;
	queue<pair<pair<int, int>, int>> Q;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int j = 0;
		for (char c : str) {
			maze[i][j++] = c;
		}
	}
	if (N == 1 && M == 1) {
		cout << 1;
		return 0;
	}
	Q.push({ {0,0},1 });
	visit[0][0][1] = true;
	while (!Q.empty()) {
		size = Q.size();
		far++;
		while (size--) {
			p = Q.front().first.first;
			q = Q.front().first.second;
			r = Q.front().second;
			for (int i = 0; i < 4; i++) {
				if (p + dx[i] >= 0 && q + dy[i] >= 0 && p + dx[i] < N && q + dy[i] < M) {
					if (maze[p + dx[i]][q + dy[i]] == '1' && r) {
						visit[p + dx[i]][q + dy[i]][r - 1] = true;
						Q.push({ {p + dx[i], q + dy[i] }, r - 1 });
					}
					else if (maze[p + dx[i]][q + dy[i]] == '0' && !visit[p + dx[i]][q + dy[i]][r]) {
						if (p + dx[i] == N - 1 && q + dy[i] == M - 1) {//길찾기 완료
							clear = true;
							size = 0;
							while (!Q.empty())
								Q.pop();
							break;
						}
						visit[p + dx[i]][q + dy[i]][r] = true;
						Q.push({ {p + dx[i], q + dy[i] }, r });
					}

				}
			}
			if (!clear) {
				Q.pop();
			}
		}
	}
	if (!clear)
		cout << -1;
	else cout << far + 1;
	return 0;
}