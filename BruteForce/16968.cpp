#include <iostream>

using namespace std;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	string inputString;
	int ans = 1;
	cin >> inputString;

	char bef = 0;
	for (char c : inputString) {
		if (c == 'c') {
			if (c == bef)
				ans *= 25;
			else
				ans *= 26;
		}
		else {
			if (c == bef)
				ans *= 9;
			else
				ans *= 10;
		}
		bef = c;
	}

	cout << ans;
}