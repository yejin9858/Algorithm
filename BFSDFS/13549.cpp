#include <string>
#include <string.h>
#include <iostream>
#include <queue>
using namespace std;


int visit[100001];
// 4000048
//
int n, k;
bool check(int pos);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> k;

	int now, t = 0;
	queue<pair<int, int>> q;

	if (n == k) {
		cout << 0;
		return 0;
	}
	else if (n > k) {
		cout << n - k;
		return 0;
	}

	q.push({ n, 1 });
	visit[n] = 1;

	while (!q.empty()) {
		now = q.front().first;
		t = q.front().second;

		if (now * 2 < k + (k-n) &&  now*2 <= 100000 && (visit[now * 2] == 0 || t < visit[now * 2])){
			q.push({ now * 2 , t });
			visit[now * 2] = t;
		}

		if (now + 1 < k + (k - n) && now + 1 <= 100000 && (visit[now + 1] == 0 || t +1 < visit[now + 1])) {
			q.push({ now + 1, t + 1 });
			visit[now + 1] = t+1;
		}

		if (now -1 > n - (k-n) && now - 1 > 0 && (visit[now - 1] == 0 || t +1 < visit[now - 1])) {
			q.push({ now - 1, t + 1 });
			visit[now - 1] = t+1;
		}
		q.pop();
	}

	cout << visit[k]-1;



}

bool check(int pos) {
	return pos == k;
}

