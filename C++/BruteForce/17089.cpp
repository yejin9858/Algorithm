#include <iostream>
#include <vector>
using namespace std;

bool friendsMap[4001][4001];
int N, M;
int ans;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;
	ans = M * N;

	for (int i = 0; i < M; i++) {
		int man1, man2;
		cin >> man1 >> man2;
		friendsMap[man1][man2] = true;
		friendsMap[man2][man1] = true;
	}

	for (int a = 1; a <= N - 2; a++) {
		for (int b = a; b <= N - 1; b++) {
			if (friendsMap[a][b]) {
				for (int c = b; c <= N; c++) {
					if (friendsMap[a][c] && friendsMap[b][c]) {
						int total = 0;
						for (int i = 1; i <= N; i++) {
							total += friendsMap[a][i] + friendsMap[b][i] + friendsMap[c][i];
						}
						ans = (total - 6) < ans ? (total - 6) : ans;
					}
				}
			}
		}
	}

	if (ans == N * M) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}