#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> schedule;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		schedule.push_back({ b,a });
	}

	sort(schedule.begin(), schedule.end());


	int bfTime = schedule[0].first;
	int maxNum = 1;

	for (int i = 1; i < N; i++) {
		if (schedule[i].second >= bfTime) {
			maxNum++;
			bfTime = schedule[i].first;
		}
	}

	cout << maxNum;
	return 0;
}