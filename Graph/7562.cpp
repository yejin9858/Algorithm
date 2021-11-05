#include <queue>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

bool board[300][300];
int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	queue<pair<int, int>> Q;
	int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
	int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
	int T, I, x, y, nx, ny, p, q, size, far = 0;
	bool clear = false;
	cin >> T;
	while (T--) {
		cin >> I >> x >> y >> nx >> ny;
		if (x == nx && y == ny) {
			cout << 0 << "\n";
			continue;
		}
		Q.push({ x,y });
		board[x][y] = true;
		while (!Q.empty()) {
			size = Q.size();
			far++;
			while (size--) {
				p = Q.front().first;
				q = Q.front().second;
				for (int i = 0; i < 8; i++) {
					if (p + dx[i] >= 0 && q + dy[i] >= 0 && p + dx[i] < I && q + dy[i] < I && !board[p + dx[i]][q + dy[i]]) {
						if (p + dx[i] == nx && q + dy[i] == ny) {
							clear = true;
							break;
						}
						board[p + dx[i]][q + dy[i]] = true;//다른 경로일때 지나갔던 곳을 지나가야 한다면??
						Q.push({ p + dx[i], q + dy[i] });
					}
				}
				if (clear) {
					while (!Q.empty())
						Q.pop();
					break;
				}
				else Q.pop();
			}
		}
		cout << far << "\n";
		far = 0;
		clear = false;
		memset(board, false, sizeof(board));
	}
}