#include<iostream>
using namespace std;

int D[201][201];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
		D[1][i] = 1;

	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			cout << i << " " << j << "\n";
			for (int l = 0; l <= j; l++) {
				D[i][j] = (D[i][j] + D[i - 1][j - l]) % 1000000000;
			}
		}
	}

	cout << D[K][N];
}