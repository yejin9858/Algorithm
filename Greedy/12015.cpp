#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int a[1000001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	auto it = v.begin();
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}


	v.push_back(a[0]);
	for (int i = 1; i < N; i++) {
		if (v.back() < a[i]) v.push_back(a[i]);
		else {
			it = v.begin();
			it = lower_bound(v.begin(), v.end(), a[i]);
			*it = a[i];
		}
	}
	cout << v.size();
	return 0;
}