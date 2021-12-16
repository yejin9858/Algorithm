#include <queue>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

char canvas[101][101];
char color[101][101];
int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	queue<pair<int, int>> Q;
	int N, paint = 0, p, q;
	char alpha = 0;
	string str;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int j = 0;
		for (char c : str) {
			canvas[i][j] = c;
			if (c == 'G')
				color[i][j++] = 'R';
			else color[i][j++] = c;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (canvas[i][j] != '0') {
				alpha = canvas[i][j];
				paint++;
				Q.push({ i,j });
				canvas[i][j] = '0';
				while (!Q.empty()) {
					p = Q.front().first;
					q = Q.front().second;
					for (int k = 0; k < 4; k++) {
						if (p + dx[k] >= 0 && q + dy[k] >= 0 && p + dx[k] < N && q + dy[k] < N && canvas[p + dx[k]][q + dy[k]]!='0' && canvas[p + dx[k]][q + dy[k]] == alpha) {
							Q.push({ p + dx[k],q + dy[k] });
							canvas[p + dx[k]][q + dy[k]] = '0';
						}
					}
					Q.pop();
				}
			}
		}
	}
	cout << paint << " ";
	paint = 0;
	alpha = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (color[i][j] != '0') {
				alpha = color[i][j];
				paint++;
				Q.push({ i,j });
				color[i][j] = '0';
				while (!Q.empty()) {
					p = Q.front().first;
					q = Q.front().second;
					for (int k = 0; k < 4; k++) {
						if (p + dx[k] >= 0 && q + dy[k] >= 0 && p + dx[k] < N && q + dy[k] < N && color[p + dx[k]][q + dy[k]] != '0' && color[p + dx[k]][q + dy[k]] == alpha) {
							Q.push({ p + dx[k],q + dy[k] });
							color[p + dx[k]][q + dy[k]]  = '0';
						}
					}
					Q.pop();
				}
			}
		}
	}
	cout << paint;
}