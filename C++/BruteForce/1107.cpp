#include<iostream>
using namespace std;

int N;
int M;
int buttons[11];

bool check(int now);
int digit(int num);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++)
		cin >> buttons[i];

	int ans = (N > 100) ? N - 100 : 100 - N;

	int num = 0;
	int now = 0;
	if (M != 10 || N!=100) {
		while (true) {
			//-
			if (N - num >= 0) {
				if (check(N - num)) {
					now = N - num;
					break;
				}
			}
			//+
			if (check(N + num)) {
				now = N + num;
				break;
			}
			num++;

			if (num > ans)
				break;
		}
		ans = min(ans, num + digit(now));
	}
	cout << ans;
	
}

bool check(int now) {
	if(now == 0)
		for (int j = 0; j < M; j++) {
			if (!buttons[j])
				return false;
		}

	for (int i = now; i > 0; i /= 10) {
		int num = i % 10;
		for (int j = 0; j < M; j++) {
			if (num == buttons[j])
				return false;
		}
	}

	return true;
}

int digit(int num) {
	if (!num) return 1;
	int count = 0;
	for (int i = num; i > 0; i /= 10) {
		count++;
	}
	return count;
}