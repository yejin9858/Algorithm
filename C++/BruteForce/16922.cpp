#include<iostream>
using namespace std;
bool num[1000];
int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int N;
	cin >> N;

	int rome[4] = { 1,5,10,50 };
	int ans = 0;

	for (int a = 0; a <= N; a++) {
		for (int b = 0; b <= N - a; b++) {
			for (int c = 0; c <= N - a - b; c++) {
				int d = N - a - b - c;
				int now = a * 1 + b * 5 + c * 10 + d * 50;
				if (!num[now]) {
					num[now] = true;
					ans++;
				}
			}
		}
	}
	
	cout << ans;
}