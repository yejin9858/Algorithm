#include <string>
#include <iostream>
using namespace std;

int d[100001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < 3; i++)
		d[1][i] = 1;

	for (int i = 2; i <= N; i++) {
		d[i][0] = (d[i - 1][0] + d[i - 1][1] + d[i - 1][2]) % 9901;
		d[i][1] = (d[i - 1][0] + d[i - 1][2]) % 9901;
		d[i][2] = (d[i - 1][0] + d[i - 1][1]) % 9901;
	}

	cout << (d[N][0] + d[N][1] + d[N][2]) % 9901;
}