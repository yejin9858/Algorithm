#include<iostream>
using namespace std;

int D[100001];
int A[100001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int ans = -1000;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
		D[i] = max(D[i - 1] + A[i], A[i]);
		if (D[i] > ans)
			ans = D[i];
	}

	cout << ans;
}