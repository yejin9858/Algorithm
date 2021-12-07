#include <string>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

bool ans = false;
void dfs(int count, int now, vector<vector<int>>& edge, vector<bool>& visit);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N , M;
	cin >> N >> M;

	vector<vector<int>> edge(N);

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}

	for (int i = 0; i < N; i++) {
		vector<bool> visit(N);
		visit[i] = true;
		dfs(0, i, edge, visit);
		if (ans) break;
	}

	cout << ans;

} 

void dfs(int count, int now, vector<vector<int>> &edge, vector<bool> &visit) {
	if (count == 4) {
		ans = true;
		return;
	}

	for (int i = 0; i < edge[now].size(); i++) {
		int tmp = edge[now][i];
		if (visit[tmp]) continue;
		visit[tmp] = true;
		dfs(count + 1, tmp, edge, visit);
		visit[tmp] = false;
	}
}