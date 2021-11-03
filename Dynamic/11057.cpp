#include <string>
#include <iostream>
using namespace std;

int d[1001][10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		d[i][0] = 1;
	for (int i = 0; i <= 9; i++)
		d[1][i] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int p = 0; p <= j; p++) {
				d[i][j] += d[i - 1][p] % 10007;
			}
		}
	}

	int sum = 0;
	for (int j = 0; j <= 9; j++) {
		sum += d[N][j];
	}
	cout << sum % 10007;

}