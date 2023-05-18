#include<iostream>
using namespace std;

int paper[3000][3000];
int ans[3] = { 0,0,0 };

void check(int x, int y, int size) {
	int num = paper[x][y];
	if (size == 1) {
		ans[num + 1] += 1;
	}
	else {
		bool flag = true;
		for (int i = x; i < x + size && flag; i++) {
			for (int j = y; j < y + size && flag; j++) {
				if (paper[i][j] != num) {
					//½ÇÆÐ
					int first = size / 3;
					int second = size / 3 * 2;
					check(x, y, first);
					check(x, y + first, first);
					check(x, y + second, first);
					check(x + first, y, first);
					check(x + first, y + first, first);
					check(x + first, y + second, first);
					check(x + second, y, first);
					check(x + second, y + first, first);
					check(x + second, y + second, first);
					flag = false;
				}

			}
		}
		if (flag) {
			ans[num + 1] += 1;
		}
	}
}

int main(void) {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> paper[i][j];
		}
	}
	check(1, 1, N);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
	}
}