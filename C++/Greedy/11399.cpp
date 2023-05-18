#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int P[1000]; 
void sort(int left, int right);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	sort(0, N - 1);

	for (int i = 0; i < N; i++) {
		ans += P[i] * (N - i);
	}

	cout << ans;

}

void sort(int left, int right) {
	int pivot;
	int i, j;
	int tmp;

	if (left < right) {
		i = left;
		j = right + 1;
		pivot = P[left];

		do {
			do { i++; } while (P[i] < pivot && i <= right);
			do { j--; } while (P[j] > pivot && j >= left);
			if (i < j) {
				tmp = P[i];
				P[i] = P[j];
				P[j] = tmp;
			}

		} while (i < j);

		tmp = P[left];
		P[left] = P[j];
		P[j] = tmp;

		sort(left, j - 1);
		sort(j + 1, right);
	}
}