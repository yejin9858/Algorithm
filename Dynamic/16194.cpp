#include<stdio.h>
#include <iostream>
using namespace std;

int d[1001];
int p[1001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = p[i];
		for (int j = 1; j < i; j++) {
			d[i] = min(d[i], d[j] + p[i - j]);
		}
	}

	cout << d[n];
	return 0;
}