#include<iostream>
using namespace std;

int D[1001];
int A[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= N; i++) {
		D[i] = 1;
		for (int j = 1; j < i; j++) {

			if (A[i] > A[j] && D[i] < D[j]+1) {
				D[i] = D[j] + 1;
			}
		}
		ans = max(D[i], ans);
	}

	cout << ans;

	return 0;
}