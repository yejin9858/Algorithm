#include<iostream>
using namespace std;

int Ns[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string N;
	cin >> N;

	int N_sum = 0;

	for (char c : N) {
		int num = c - 48;
		Ns[num] ++;
		N_sum += num;
	}

	if (!Ns[0] || N_sum % 3)	cout << -1;
	else {
		for (int i = 9; i >= 0; i--) {
			while (Ns[i] > 0) {
				cout << i;
				Ns[i] --;
			}
		}
	}

	return 0;
}