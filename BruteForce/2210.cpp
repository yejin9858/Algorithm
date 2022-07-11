#include <iostream>
#include <queue>
using namespace std;


int board[5][5];
bool variety[1000000];
queue <pair<pair<int, int>, pair<int, int>>> numSum;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int is[] = { -1,0,1,0 };
	int js[] = { 0,-1,0,1 };
	int ans = 0;

	int num;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> num;
			board[i][j] = num;
			numSum.push({ { i,j }, {num , 0} });
		}
	}

	pair<pair<int, int>, pair<int, int>> now;
	pair<pair<int, int>, pair<int, int>> add;
	while (!numSum.empty()) {
		now = numSum.front();
		for (int k = 0; k < 4; k++) {
			int i = now.first.first + is[k];
			int j = now.first.second + js[k];
			if (i < 5 && i >= 0 && j < 5 && j >= 0) {
				add.first.first = i;
				add.first.second = j;
				add.second.first = now.second.first * 10 + board[add.first.first][add.first.second];
				add.second.second = now.second.second+1;
				if (add.second.second == 5) {
					variety[add.second.first] = true;
				}
				else {
					numSum.push(add);
				}
			}
		}
		numSum.pop();
	}

	for (int i = 0; i < 1000000; i++) {
		if (variety[i]) ans++;
	}

	cout << ans;

}