#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int A[100002];
int D[100001][2];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, ans;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	ans = A[0];
	D[0][0] = A[0];
	D[0][1] = A[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			D[i][0] = A[i];
			D[i][1] = A[i];
			if (D[i - 1][0] + A[i] > D[i][0])
				D[i][0] += D[i - 1][0];
			if (D[i - 1][1] + A[i] > D[i][1])
				D[i][1] += D[i - 1][1];
			if (D[i-1][0] > D[i][1])
				D[i][1] = D[i - 1][0];
		}
		ans = max(ans, D[i][0]);
		ans = max(ans, D[i][1]);
	}

	cout << ans;
}