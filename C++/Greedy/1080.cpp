#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int matrix[50][50];
int answer[50][50];
void filpMatrix(int x, int y);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	int ans = 0;
	string s;

	for (int i = 0; i < N; i++) {
		cin >> s;
		int j = 0;
		for (char c : s) {
			matrix[i][j++] = c - 48;
		}
	}

	for (int i = 0; i < N; i++) {
		cin >> s;
		int j = 0;
		for (char c : s) {
			answer[i][j++] = c - 48;
		}
	}

	if (N < 3 || M < 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (matrix[i][j] != answer[i][j]) {
					cout << -1;
					return 0;
				}
			}
		}
		cout << 0;
		return 0;
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (matrix[i][j] != answer[i][j]) {
				filpMatrix(i, j);
				ans++;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (matrix[i][j] != answer[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	
	cout << ans;
}

void filpMatrix(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			matrix[i][j] = (matrix[i][j] + 1)%2;
		}
	}
}
