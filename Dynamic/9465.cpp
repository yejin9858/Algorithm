#include <string>
#include <iostream>
#include<string.h>
using namespace std;

int d[2][100002];
int a[2][100002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;

		for (int l = 0; l < 2; l++) {
			for (int m = 0; m < n; m++) {
				cin >> a[l][m];
			}
		}

		d[0][0] = a[0][0];
		d[1][0] = a[1][0];

		for (int m = 0; m < n - 1; m++) {
			for (int l = 0; l < 2; l++) {
				int j = (l + 1) % 2;
				if (d[j][m + 1] < d[l][m] + a[j][m + 1]) {
					d[j][m + 1] = d[l][m] + a[j][m + 1];
				}
				if (d[j][m + 2] < d[l][m] + a[j][m + 2] && m + 2 < n) {
					d[j][m + 2] = d[l][m] + a[j][m + 2];
				}
			}
		}

		cout << max(d[0][n - 1], d[1][n - 1]) <<"\n";

		memset(d[0], 0, sizeof(d[0]));
		memset(d[1], 0, sizeof(d[1]));
	}
}