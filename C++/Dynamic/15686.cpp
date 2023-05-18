#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int map[51][51];
int map_distance[51][51];
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int N, M;
int ans = 1300;

int measureChickenDistance(vector<pair<int, int>> chickenHouses) {
	int distances[100] = { 0 };
	int ans = 0;
	for (int i = 0; i < chickenHouses.size(); i++) {
		for (int j = 0; j < house.size(); j++) {
			int distance = abs(house[j].first - chickenHouses[i].first) + abs(house[j].second - chickenHouses[i].second);
			if (distances[j] == 0 || distance < distances[j])
				distances[j] = distance;
		}
	}
	for (int i = 0; i < house.size(); i++) {
		ans += distances[i];
	}
	return ans;
}

void selectChickenHouse(vector<pair<int, int>> chickenHouses, int index) {
	if (chickenHouses.size() == M) {
		ans = min(ans, measureChickenDistance(chickenHouses));
	}
	if (index > chicken.size() -1 || chickenHouses.size() >= M) {
		return;
	}
	selectChickenHouse(chickenHouses, index + 1);
	chickenHouses.push_back(chicken[index]);
	selectChickenHouse(chickenHouses, index + 1);
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				chicken.push_back({ i,j });
			}
			else if (map[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}

	vector<pair<int,int>> chickenHouses;
	selectChickenHouse(chickenHouses, 0);

	cout << ans;

}