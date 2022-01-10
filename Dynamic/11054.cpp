#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int A[1001];
int Du[1001];
int Dd[1001];

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
		Du[i] = 1;
		for (int j = 1; j < i; j++) {

			if (A[i] > A[j] && Du[i] < Du[j] + 1) {
				Du[i] = Du[j] + 1;
			}
		}
	}

	for (int h = 0; h <= N; h++) {
		int downMax = 0;
		for (int i = h + 1; i <= N; i++) {
			Dd[i] = 1;
			if (A[h] != A[h + 1]) {
			for (int j = h + 1; j < i; j++) {
				if (A[i] < A[j] && Dd[i] < Dd[j] + 1 && A[h] != A[j]) {
					Dd[i] = Dd[j] + 1;
				}
				downMax = max(downMax, Dd[i]);
			}
		}
        }

		ans = max(Du[h] + downMax, ans);

		memset(Dd, 0, sizeof(Dd));
	}


	cout << ans;

	return 0;
}