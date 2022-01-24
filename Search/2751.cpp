#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

int a[1000000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N);

	for (int i = 0; i < N; i++) {
		cout << a[i] << "\n";
	}

	return 0;
}