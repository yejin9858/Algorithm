#include<iostream>
#include<algorithm>
using namespace std;

int a[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int ans = 0;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a+N);

	int flag = 0;

	while (a[flag] <= 0 && flag < N) {
		if (a[flag + 1] <= 0 && flag + 1 < N) {
			ans += a[flag] * a[flag + 1];
			flag += 2;
		}
		else {
			ans += a[flag];
			flag++;
		}
	}

	while (a[flag] == 1) {
		ans++;
		flag++;
	}

	for (int i = N - 1; i >= flag; i--) {
		if (i - 1 >= flag) {
			ans += a[i] * a[i - 1];
			i--;
		}
		else {
			ans += a[i];
		}
	}

	cout << ans;

}