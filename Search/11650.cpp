#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	int i, j;
	for (int k = 0; k < N; k++) {
		cin >> i >> j;
		v.push_back({ j, i });
	}
	sort(v.begin(), v.end());

	for (int k = 0; k < v.size(); k++) {
		cout << v[k].second << " " << v[k].first << "\n";
	}
	return 0;
}