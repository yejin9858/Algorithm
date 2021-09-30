#include<iostream>
using namespace std;

int d[1001];
int p[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	d[1] = p[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			d[i] = max(d[i], d[j] + p[i - j]);
		}
	}
	
	cout << d[n];
	return 0;
}