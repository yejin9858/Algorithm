#include<iostream>
using namespace std;

int star[3072][6144];
int N;

void setStar(int top, int bottom, int col) {
	int height = bottom - top + 1;
	if (height == 3) {
		star[top][col] = 1;
		star[top + 1][col - 1] = 1;
		star[top + 1][col + 1] = 1;
		for (int i = 0; i < 5; i++) {
			star[bottom][col - i + 2] = 1;
		}
		return;
	}

	setStar(top, top + height/2 - 1, col);
	setStar(top + height / 2, bottom, col - height / 2);
	setStar(top + height / 2, bottom, col + height / 2);
}

void printStar() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++) {
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

	setStar(0, N - 1, N - 1);
	printStar();

}