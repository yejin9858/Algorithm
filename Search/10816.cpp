#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int s[20000001];
int c[500001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		s[num + 10000000]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < M; i++) {
		cout << s[c[i] + 10000000] <<" ";
	}

	return 0;

}