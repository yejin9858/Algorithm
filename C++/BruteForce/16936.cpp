#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> B;
bool isFindAnswer = false;

void findOriginal(long long root, vector<long long> list, vector<long long> left) {
	if (list.size() == B.size()) {
		for (int i = 0; i < B.size(); i++) {
			cout << list.at(i) << " ";
		}
		isFindAnswer = true;
		return;
	}
	if (root % 3 == 0) {
		vector<long long> tmpLeft = left;
		vector<long long> tmpList = list;
		auto it = find(tmpLeft.begin(), tmpLeft.end(), root / 3);
		if (it != tmpLeft.end()) {
			tmpLeft.erase(it);
			tmpList.push_back(root / 3);
			findOriginal(root / 3, tmpList, tmpLeft);
		}
	}
	vector<long long> tmpLeft = left;
	vector<long long> tmpList = list;
	auto it = find(tmpLeft.begin(), tmpLeft.end(), root *2);
	if (it != tmpLeft.end()) {
		tmpLeft.erase(it);
		tmpList.push_back(root * 2);
		findOriginal(root * 2, tmpList, tmpLeft);
	}
	return;
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long n;
		cin >> n;
		B.push_back(n);
	}

	for (int i = 0; i < B.size(); i++) {
		long long root = B.at(i);
		vector<long long> now;
		vector<long long> left = B;
		left.erase(left.begin() + i);
		now.push_back(root);
		findOriginal(root, now, left);
		if (isFindAnswer)
			return 0;
	}

	cout << -1;
	return 0;
}