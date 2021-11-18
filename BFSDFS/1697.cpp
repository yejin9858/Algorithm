#include <queue>
#include <string>
#include <iostream>
using namespace std;

bool visit[100001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, K, now, size, time = 0;
	queue<int> Q;
	cin >> N >> K;
	if (N == K) {
		cout << time;
		return 0;
	}
	if (N > K) {
		cout << N - K;
		return 0;
	}
	Q.push(N);
	visit[N] = true;
	while (true) {
		time++;
		size = Q.size();
		while (size--) {
			now = Q.front();
			if (now + 1 <= 100000 && !visit[now + 1]) {
				if (now + 1 == K) {
					cout << time;
					return 0;
				}
				Q.push(now + 1);
				visit[now + 1] = true;
			}
			if (now - 1 > 0 && !visit[now - 1]) {
				if (now - 1 == K) {
					cout << time;
					return 0;
				}
				Q.push(now - 1);
				visit[now - 1] = true;
			}
			if (now * 2 <= 100000 && !visit[now * 2]) {
				if (now * 2 == K) {
					cout << time;
					return 0;
				}
				Q.push(now * 2);
				visit[now * 2] = true;
			}
			Q.pop();
		}
	}
}