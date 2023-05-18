#include<iostream>
#include<queue>
using namespace std;

int visit[1001][1001];

int main(void) {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);

	int S;
	cin >> S;

	int clip = 1;
	int now = 1;
	int t = 1;

	queue<pair<pair<int, int>, int>> q;

	q.push({ { clip, now }, t });

	while (true) {

		clip = q.front().first.first;
		now = q.front().first.second;
		t = q.front().second;
		if (!visit[now][now]) {
			q.push({ {now, now},t + 1 });
			visit[now][now] = true;
		}
		if (now + clip <= 1000) {
			if (!visit[clip][now + clip]) {
				q.push({ {clip, now + clip}, t + 1 });
				visit[clip][now + clip] = true;
			}
		}

		if (!visit[clip][now - 1] && now > 1) {
			q.push({ {clip, now - 1}, t + 1 });
			visit[clip][now - 1] = true;
		}

		if (now + clip == S || now - 1 == S) {
			cout << t + 1;
			return 0;
		}

		q.pop();

	}
}