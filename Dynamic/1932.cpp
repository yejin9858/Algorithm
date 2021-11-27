#include <string>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int d[500][1000];
int s[500][1000];


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	for (int i = 500, j = 0; j < n; i--, j++) {
		cin >> d[j][i];
		int tmp = i;
		for (int k = j; k > 0; k--) {
			tmp += 2;
			cin >> d[j][tmp];
		}
	}

	s[0][500] = d[0][500];
	for (int i = 500, j = 0; j < n - 1; i--, j++) {
		int tmp = i;
		for (int k = j; k >= 0; k--, tmp += 2) {
			if (s[j][tmp] + d[j + 1][tmp - 1] > s[j + 1][tmp - 1])
				s[j + 1][tmp - 1] = s[j][tmp] + d[j + 1][tmp - 1];
			if (s[j][tmp] + d[j + 1][tmp + 1] > d[j + 1][tmp + 1])
				s[j + 1][tmp + 1] = s[j][tmp] + d[j + 1][tmp + 1];
		}
	}

	int sum = 0;
	for (int i = 500 - n+1; i < 500 + n; i+=2) {
		sum = max(s[n - 1][i], sum);
	}
	cout << sum;

	/*for (int i = 0; i < 500; i++) {
		for (int j = 0; j < 1000; j++) {
			cout << d[i][j];
		}
		cout << "\n";
	}*/
}