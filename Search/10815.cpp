#include<iostream>
#include<algorithm>
using namespace std;

int a[500001];
int b[500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> b[i];
	}

	sort(a, a + N);
	
	for (int i = 0; i < M; i++) {
		int right = N - 1;
		int left = 0;
		int print = false;
		while (right >= left) {
			int mid = (right + left) / 2;
			if (a[mid] > b[i]) {
				right = mid - 1;
			}
			else if (a[mid] < b[i]) {
				left = mid + 1;
			}
			else {
				cout << "1 ";
				print = true;
				break;
			}
		}
		if (!print) cout << "0 ";
	}
	return 0;

}