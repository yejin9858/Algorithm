#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[1001];
int dp[1001];
bool visit[1001];

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	if (N == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= A[i] && i + j <= N; j++) {
				if (dp[i + j] != 0) {
					dp[i + j] = min(dp[i] + 1, dp[i + j]);
				}
				else {
					dp[i + j] = dp[i] + 1;
				}
				visit[i + j] = true;
			
		}
	}

	if (dp[N] == 0) {
		cout << -1;
		return 0;
	}

	for (int i = 2; i <= N; i++) {
		if (!visit[i]) {
			cout << -1;
			return 0;
		}
	}

	cout << dp[N];
	return 0;
}