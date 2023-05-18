#include<iostream>
using namespace std;

long long d[101][10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		d[i][0] = d[i - 1][1];
		for (int j = 1; j < 9; j++) {
			d[i][j] = (d[i - 1][j - 1] + d[i - 1][j + 1]) % 1000000000;
		}
		d[i][9] = d[i - 1][8];
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans += d[N][i];

	cout << ans % 1000000000;

	return 0;
}