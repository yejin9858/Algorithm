#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int coin[21][21];
int copy_coin[21][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, ans = 0;
	cin >> N;

	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		int j = 1; 
		for (char c : str) {
			if (c == 'T') {
				coin[i][j++] = 1;
				ans++;
			}
			else j++;
		}
	}

	for (int i = 0; i < (1 << N); i++) {

		//복사
		for (int j = 1; j <= N; j++)
			for (int k = 1; k <= N; k++) 
				copy_coin[j][k] = coin[j][k];

		//행 뒤집기
		for (int j = 1; j <= N; j++) {
			int this_col = 1 << (j - 1);
			if (this_col & i) {
				for (int k = 1; k <= N; k++) {
					copy_coin[j][k] = !copy_coin[j][k];
				}
			}
		}

		//열 뒤집기
		int count = 0;
		for (int j = 1; j <= N; j++) {
			int now = 0;
			for (int k = 1; k <= N; k++) {
				now += copy_coin[k][j];
			}
			count += min(now, N - now);
		}
		ans = min(ans, count);
	}

	cout << ans << "\n";
	return 0;
}
