#include <iostream>
using namespace std;

int height[100];

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int C, P;
	cin >> C >> P;

	for (int i = 0; i < C; i++) {
		cin >> height[i];
	}
	int sum = 0;

	int accum = 1;

	switch (P) {
	case 1:
		sum += C;
		for (int i = 3; i < C; i++) {
			if (height[i - 3] == height[i - 2] && height[i - 2] == height[i - 1] && height[i - 1] == height[i]) {
				sum++;
			}
		}
		if (accum >= 4) {
			sum += accum - 3;
		}
		break;
	case 2:
		for (int i = 1; i < C; i++) {
			if (height[i - 1] == height[i]) {
				sum++;
			}
		}
		break;
	case 3:
		for (int i = 2; i < C; i++) {
			if (height[i - 2] == height[i - 1] && height[i - 1] + 1 == height[i]) {
				sum++;
			}
		}
		for (int i = 1; i < C; i++) {
			if (height[i - 1] == height[i]+1) {
				sum++;
			}
		}
		break;
	case 4:
		for (int i = 2; i < C; i++) {
			if (height[i - 2] == height[i - 1] +1 && height[i - 1] == height[i]) {
				sum++;
			}
		}
		for (int i = 1; i < C; i++) {
			if (height[i - 1] +1 == height[i]) {
				sum++;
			}
		}
		break;
	case 5:
		for (int i = 2; i < C; i++) {
			if (height[i - 2] == height[i - 1] && height[i - 1] == height[i]) {
				sum++;
			}
			if (height[i - 2] == height[i - 1] + 1 && height[i - 1] + 1 == height[i]) {
				sum++;
			}
		}
		for (int i = 1; i < C; i++) {
			if (height[i - 1] + 1 == height[i]) {
				sum++;
			}
			if (height[i - 1] == height[i] + 1) {
				sum++;
			}
		}
		break;
	case 6:
		for (int i = 2; i < C; i++) {
			if (height[i - 2] == height[i - 1] && height[i - 1] == height[i]) {
				sum++;
			}
			if (height[i - 2] + 1 == height[i - 1] && height[i - 1] == height[i]) {
				sum++;
			}
		}

		for (int i = 1; i < C; i++) {
			if (height[i - 1] == height[i]) {
				sum++;
			}
			else if (height[i - 1] == height[i] + 2) {
				sum++;
			}
		}
		break;

	case 7:
		for (int i = 2; i < C; i++) {
			if (height[i - 2] == height[i - 1] && height[i - 1] == height[i]) {
				sum++;
			}
			if (height[i - 2] == height[i - 1] && height[i - 1] == height[i] + 1) {
				sum++;
			}
		}

		for (int i = 1; i < C; i++) {
			if (height[i - 1] == height[i]) {
				sum++;
			}
			else if (height[i - 1] + 2 == height[i]) {
				sum++;
			}
		}
		break;
	}
	cout << sum;


}