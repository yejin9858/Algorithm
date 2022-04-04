#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int,int>>> sticker;

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int H, W, N;
	cin >> H >> W >> N;

	for (int i = 0; i < N; i++) {
		int sh, sw;
		cin >> sh >> sw;
		sticker.push_back({ sh * sw,{sh, sw} });
	}

	sort(sticker.begin(), sticker.end(), greater<>());
	
	int ans = 0;
	for (int i = 0; i < sticker.size(); i++) {
		pair<int, pair<int, int>> one = sticker[i];
		int sum = 0;
		int leftH, leftW;
		if (one.first < H * W) {
			if (one.second.first <= H && one.second.second <= W) {
				sum += one.first;
				leftH = H - one.second.first;
				leftW = W - one.second.second;
				for (int j = i + 1; j < sticker.size(); j++) {
					pair<int, pair<int, int>> two = sticker[j];

					if ((two.second.first <= leftW && two.second.second <= H )
						|| (two.second.first <= H && two.second.second <= leftW)
						|| (two.second.first <= W && two.second.second <= leftH)
						|| (two.second.first <= leftH && two.second.second <= W)) {
						sum += two.first;
						ans = (sum > ans) ? sum : ans;
						break;
					}
				}
			}
			sum = 0;
			if (one.second.first <= W && one.second.second <= H) {
				sum += one.first;
				leftH = H - one.second.second;
				leftW = W - one.second.first;
				for (int j = i + 1; j < sticker.size(); j++) {
					pair<int, pair<int, int>> two = sticker[j];

					if ((two.second.first <= leftW && two.second.second <= H)
						|| (two.second.first <= H && two.second.second <= leftW)
						|| (two.second.first <= W && two.second.second <= leftH)
						|| (two.second.first <= leftH && two.second.second <= W)) {
						sum += two.first;
						ans = (sum > ans) ? sum : ans;
						break;
					}
				}
			}
		}

	}
	cout << ans;
	return 0;
}