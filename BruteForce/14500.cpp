#include <iostream>
#include<queue>
using namespace std;

int d[501][501];
int h, w;

int shape1(int x, int y);
int shape2(int x, int y);
int shape3(int x, int y);
int shape4(int x, int y);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> h >> w;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			ans = max(ans, shape1(i, j));
			ans = max(ans, shape2(i, j));
			ans = max(ans, shape3(i, j));
			ans = max(ans, shape4(i, j));
		}
	}

	cout << ans;
	return 0;
}

int shape1(int x, int y) {
	int shape1_1 = 0;
	int shape1_2 = 0;

	if (x <= h - 3) {
		shape1_1 = d[x][y] + d[x + 1][y] + d[x + 2][y] + d[x + 3][y];
	}

	if (y <= w - 3) {
		shape1_2 = d[x][y] + d[x][y + 1] + d[x][y + 2] + d[x][y + 3];
	}

	return max(shape1_1, shape1_2);
}

int shape2(int x, int y) {
	if (x <= h - 1 && y <= w - 1) {
		return d[x][y] + d[x + 1][y] + d[x][y + 1] + d[x + 1][y + 1];
	}
	return 0;
}

int shape3(int x, int y) {
	int shape3_1 = 0;
	int shape3_2 = 0;
	int shape3_3 = 0;
	int shape3_4 = 0;
	int shape3 = 0;

	if (x <= h - 2 && y <= w - 1) {
		int tmp = max(d[x + 2][y + 1] , d[x + 1][y + 1]);
		tmp = max(tmp , d[x][y + 1]);

		shape3_1 = d[x][y] + d[x + 1][y] + d[x + 2][y] + tmp;
		shape3 = max(shape3, shape3_1);
	}
	if (x <= h - 2 && y >= 2) {
		int tmp = max(d[x + 2][y - 1], d[x + 1][y - 1]);
		tmp = max(tmp , d[x][y - 1]);

		shape3_2 = d[x][y] + d[x + 1][y] + d[x + 2][y] + tmp;
		shape3 = max(shape3, shape3_2);
	}
	if (y <= w - 2 && x <= h - 1) {
		int tmp = max(d[x + 1][y + 2] , d[x + 1][y + 1]);
		tmp = max(tmp , d[x + 1][y]);

		shape3_3 = d[x][y] + d[x][y + 1] + d[x][y + 2] + tmp;
		shape3 = max(shape3, shape3_3);
	}
	if (y <= w - 2 && x >= 2) {
		int tmp = max(d[x - 1][y + 2] , d[x - 1][y + 1]);
		tmp = max(tmp, d[x - 1][y]);

		shape3_4 = d[x][y] + d[x][y + 1] + d[x][y + 2] + tmp;
		shape3 = max(shape3, shape3_4);
	}

	return shape3;
}

int shape4(int x, int y) {
	int shape4 = 0;

	if (x >= 2 && y <= w - 2) {
		shape4 = max(shape4,d[x][y] + d[x][y + 1] + d[x - 1][y + 1] + d[x - 1][y + 2]);
	}
	if (x <= h - 1 && y <= w - 2) {
		shape4 = max(shape4, d[x][y] + d[x][y + 1] + d[x + 1][y + 1] + d[x + 1][y + 2]);
	}
	if (x <= h - 2 && y <= w-1) {
		shape4 = max(shape4, d[x][y] + d[x + 1][y] + d[x + 1][y + 1] + d[x + 2][y + 1]);
	}
	if (x <= h - 2 && y >= 2) {
		shape4 = max(shape4, d[x][y] + d[x + 1][y] + d[x + 1][y - 1] + d[x + 2][y - 1]);
	}

	return shape4;

}