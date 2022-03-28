#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> A;
int answer = 0;
int N, L, R, X;

void calculateNumber(int index, int sum, vector<int> now) {
	if (sum > R) return;
	else if (index == A.size()) {
		if (now.size() < 2) return;
		if (now[0] - now[now.size() - 1] >= X && sum >= L) {
			answer++;
		}
		return;
	}
	calculateNumber(index + 1, sum, now);
	now.push_back(A[index]);
	calculateNumber(index + 1, sum + A[index], now);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> L >> R >> X;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		A.push_back(num);
	}

	sort(A.begin(), A.end(), greater<>());

	vector<int> vector;
	calculateNumber(0, 0, vector);
	cout << answer;
	return 0;
}