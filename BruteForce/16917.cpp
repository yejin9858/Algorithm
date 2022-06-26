#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int A, B, C, X, Y;

	cin >> A >> B >> C >> X >> Y;

	bool isABBiggerThan2C = false;
	bool isXBiggerThanY = false;

	int ans = 0;

	if (X > Y) {
		isXBiggerThanY = true;
	}

	if (2 * C < A + B) {
		isABBiggerThan2C = true;
	}

	if (isABBiggerThan2C && !isXBiggerThanY) {
		ans += X * C * 2;
		ans += (2 * C > B) ? abs(X - Y) * B : abs(X - Y) * 2 * C;
	}
	else if (isABBiggerThan2C && isXBiggerThanY) {
		ans += Y * C * 2;
		ans += (2 * C > A) ? abs(X - Y) * A : abs(X - Y) * 2 * C;
	}
	else {
		ans = X * A + Y * B;
	}

	cout << ans;
}