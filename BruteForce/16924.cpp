#include<iostream>
#include<vector>
using namespace std;

bool map[101][101];
bool check[101][101];

vector<pair<pair<int, int>, int>> answer;
int main(void) {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		int j = 1;
		for (char c : s) {
			if (c == '.') {
				map[i][j] = false;
			}
			else {
				map[i][j] = true;
			}
			j++;
		}
	}



	int locX[] = { 0, 0, 1, 0, -1 };
	int locY[] = { 0, -1, 0, 1, 0 };


	for (int i = 2; i <= N - 1; i++) {
		for (int j = 2; j <= M - 1; j++) {
			int size = 1;
			bool ok = true;
			while (ok) {
				for (int k = 0; k < 5; k++) {
					if (i + locX[k] * size >= 1 && i + locX[k] * size <= N &&
						j + locY[k] * size >= 1 && j + locY[k] * size <= M) {
						if (!map[i + locX[k] * size][j + locY[k] * size]) {
							ok = false;
							break;
						}
					}
					else {
						ok = false;
						break;
					}
				}
				if (ok) {
					answer.push_back({ { i,j},size });
					for (int k = 0; k < 5; k++) {
						check[i + locX[k] * size][j + locY[k] * size] = true;
					}
					size++;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] != check[i][j]) {
				cout << -1;
				return 0;
			}
		}
	}
	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first.first << " " << answer[i].first.second << " " << answer[i].second << "\n";
	}
	return 0;

}