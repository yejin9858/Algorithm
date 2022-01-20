#include<iostream>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	int max_team = min(N / 2, M);
	int left = N - (max_team * 2) + (M - max_team);
	
	while (left < K) {
		max_team--;
		left += 3;
	}

	cout << max_team;
	return 0;
}