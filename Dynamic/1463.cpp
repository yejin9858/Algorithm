#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int d[1000001];
int n;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;

	/*방법 1*/
	/*for (int i = n; i != 1; i--) {

		if (i - 1 > 0 && (d[i - 1] == 0 || d[i - 1] > d[i] + 1)) {
			d[i - 1] = d[i] + 1;
		}

		if (!(i % 2) && (d[i / 2] == 0 || d[i / 2] > d[i] + 1)) {
			d[i / 2] = d[i] + 1;
		}

		if (!(i % 3) && (d[i / 3] == 0 || d[i / 3] > d[i] + 1)) {
			d[i / 3] = d[i] + 1;
		}
	}*/

	/*방법 2*/
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (!(i % 2)) d[i] = min(d[i], d[i / 2] + 1);
		if (!(i % 3)) d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n];
}