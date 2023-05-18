#include <queue>
#include <string>
#include <iostream>
using namespace std;

int canvas[500][500];
int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	queue<pair<int, int>> Q;
	int h, w, max = 0, paint = 0;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> canvas[i][j];
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (canvas[i][j] == 1) {
				int n = 1, p = i, q = j;
				Q.push({ p,q });
				canvas[p][q] = 0;
				paint++;
				while (!Q.empty()) {
					p = Q.front().first;
					q = Q.front().second;
					for (int k = 0; k < 4; k++) {
						if (p + dx[k] >= 0 && q + dy[k] >= 0 && p + dx[k] < h && q + dy[k] < w) {
							if (canvas[p + dx[k]][q + dy[k]] == 1) {
								Q.push({ p + dx[k],q + dy[k] });
								canvas[p + dx[k]][q + dy[k]] = 0;
								n++;
							}
						}
					}
					Q.pop();
				}
				if (n > max) max = n;
			}
		}
	}
	cout << paint << '\n' << max;
}