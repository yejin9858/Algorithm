#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int maze[1001][1001];
int dp[1001][1001];

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
			dp[i][j] = maze[i][j];
			if (j - 1 >= 1) {
				dp[i][j] = max(maze[i][j] + dp[i][j - 1], dp[i][j]);
				if (i - 1 >= 1) {
					dp[i][j] = max(maze[i][j] + dp[i - 1][j - 1], dp[i][j]);
				}
			}
			if (i - 1 >= 1) {
				dp[i][j] = max(maze[i][j] + dp[i - 1][j], dp[i][j]);

			}
		}
	}

	cout << dp[N][M];

	return 0;
}