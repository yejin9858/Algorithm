#include <string>
#include <string.h>
#include <iostream>
using namespace std;

int A[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < 10; i++) {
		cin >> A[i];
	}
	int unit = n-1;
	int money = k;
	int coin = 0;
	while (money != 0) {
		while (A[unit] > money) unit--;
		while (money >= A[unit]) {
			money -= A[unit]; 
			coin++;
		}
	}

	cout << coin;
	return 0;
}