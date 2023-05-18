#include<iostream>
using namespace std;

void tower(int n, int from, int to) {
	if (n == 0) return;
	tower(n - 1, from, 6 - from - to);
	cout << from << " " << to << "\n";
	tower(n - 1, 6 - from - to, to);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N, t = 1;
	cin >> N;
	cout << (1 << N) - 1 << '\n';
	tower(N, 1, 3);
}