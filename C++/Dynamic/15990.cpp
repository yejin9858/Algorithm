#include<iostream>
using namespace std;

long long d[100001][4];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int n;
	cin >> T;

	d[1][1] = 1;
	d[2][2] = 1;
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;

	for (int i = 4; i < 100001; i++) {
		d[i][1] = (d[i - 1][2] + d[i - 1][3]) % 1000000009;
		d[i][2] = (d[i - 2][1] + d[i - 2][3]) % 1000000009;
		d[i][3] = (d[i - 3][1] + d[i - 3][2]) % 1000000009;
	}

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3]) % 1000000009 << "\n";
	}

}