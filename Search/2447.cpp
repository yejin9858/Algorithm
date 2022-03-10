#include<iostream>
using namespace std;

char star[10000][10000];
int N;
void pointStar(int x1, int y1, int x2, int y2) {

	if (x1 == x2 && y1 == y2) {
		star[x1][y1] = '*';
		return;
	}
	int size = (x2 - x1 + 1) / 3;

	pointStar(x1,            y1, x1 + size - 1,     y1 + size - 1);
	pointStar(x1 + size,     y1, x1 + size * 2 - 1, y1 + size - 1);
	pointStar(x1 + size * 2, y1, x2,                y1 + size - 1);

	pointStar(x1,            y1 + size, x1 + size - 1, y1 + size * 2 - 1);
	pointStar(x1 + size * 2, y1 + size, x2,            y1 + size * 2 - 1);

	pointStar(x1,            y1 + size * 2, x1 + size - 1,     y2);
	pointStar(x1 + size,     y1 + size * 2, x1 + size * 2 - 1, y2);
	pointStar(x1 + size * 2, y1 + size * 2, x2,                y2);
}

void printStar() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (star[i][j] == 0) {
				cout << ' ';
			} 
			else {
				cout << '*';
			}
		}
		cout << "\n";
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N;

	pointStar(1, 1, N, N);
	printStar();
}