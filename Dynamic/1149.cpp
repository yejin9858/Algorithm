#include <string>
#include <iostream>
using namespace std;

int d[1001][3];
int price[1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> price[i][j];
		}
	}

	for (int i = 0; i < 3; i++)
		d[1][i] = price[1][i];

	for (int i = 2; i <= N; i++) {
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + price[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + price[i][1];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + price[i][2];
	}

	cout << min(min(d[N][0], d[N][1]), d[N][2]);
}