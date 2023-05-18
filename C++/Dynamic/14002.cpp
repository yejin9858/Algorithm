#include<iostream>
using namespace std;

int D[1001];
int A[1001];
int V[1001];
int maxA;

void back(int n);

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
		V[i] = 1;
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j] && V[i] < V[j] + 1) {
				V[i] = V[j] + 1;
				D[i] = j;
			}
		}
		if (V[i] > ans) {
			ans = V[i];
			maxA = i;
		}
	}

	cout << ans << "\n";
	back(maxA);

	return 0;
}

void back(int n) {
	if (n == 0)
		return;
	back(D[n]);
	cout << A[n] << " ";
	return;
}