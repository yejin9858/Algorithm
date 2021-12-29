#include <string>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;

int D[31];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans = 0;
	cin >> n;

	if (n % 2) {
		cout << 0;
		return 0;
	}
	D[0] = 1;
	D[2] = 3;
	for (int i = 4; i <= n; i += 2) {
		D[i] += D[i - 2] * 3;
		for (int j = i - 4; j >= 0; j = j - 2)
		{
			D[i] += D[j] * 2;
		}
	}
	cout << D[n];
}
