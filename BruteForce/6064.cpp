#include <iostream>
using namespace std;

bool flag = false;
void calculate(int ans, int ori, int add, int minus);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		flag = false;
		if (x > M || y > N) {
			cout << -1 << "\n";
			continue;
		}

		if (M <= N) 
			calculate(y, x, M, N);
		else 
			calculate(x, y, N, M);
	}
}

void calculate(int ans, int ori, int add, int minus) {
	int year = ori, chan = ori;
	while (true) {
		if (chan == ans) {
			cout << year << "\n";
			break;
		}
		else if (chan == ori && flag) {
			cout << -1 << "\n";
			break;
		}
		year += add;
		chan += add;
		if (chan > minus)
			chan -= minus;
		flag = true;
	}
}