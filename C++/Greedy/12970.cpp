#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	if (K > (N * N / 4)) {
		cout << "-1";
		return 0;
	}
	else if (K == 0) {
		cout << "B";
		for (int i = N-1; i > 0; i--) {
			cout << "A";
		}
		return 0;
	}
	else if (K < N) {
		int a = N - K - 1;
		for (int i = a; i > 0; i--) {
			cout << "B";
		}
		for (int i = K; i > 0; i--) {
			cout << "A";
		}
		cout << "B";
		return 0;
	}
	else {
		int a = 0, b;
		while (a < N) {
			b = sqrt(K - a);
			int c = K / b;
			int azero = (a == 0) ? 0 : 1;
			if (!((K - a) % b) && b + c + azero <= N) {
				for (int i = a; i > 0; i--) {
					cout << "A";
				}
				if(a)
					cout << "B";
				for (int i = b - a; i > 0; i--) {
					cout << "A";
				}
				for (int i = c; i > 0; i--) {
					cout << "B";
				}
				for (int i = N - b - c - azero; i > 0; i--) {
					cout << "A";
				}
				return 0;
			}
			else {
				a++;
			}
		}
	}
	cout << "-1";
	return 0;
}