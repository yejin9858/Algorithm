#include<iostream>
using namespace std;

int d[1001];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	d[1] = 1;
	d[2] = 3;

	for (int i = 1; i < n - 1; i++) {
		d[i + 2] = (2 * d[i] + d[i + 1]) % 10007;
	}

	cout << d[n];

	return 0;
}