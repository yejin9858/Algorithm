#include<iostream>
#include<map>
using namespace std;

int main() {

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	map<long long, int> map;
	int max_num = 0;
	long long max_card = 0;

	while (N-- > 0) {
		long long num;
		cin >> num;

		if (map.find(num) == map.end()) {
			map.insert({ num, 1 });
		}
		else {
			int tmp = map[num];
			map.erase(num);
			map.insert({ num,  tmp+1});
		}
		if (max_num <= map[num]) {
			if (max_num != map[num] || num < max_card) {
				max_card = num;
			}
			max_num = map[num];
		}
		max_num = max(max_num, map[num]);
	}

	cout << max_card;
	return 0;
}