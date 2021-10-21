#include <iostream>
#include <math.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	int N, sum = 0;
	cin >> N;
	/*
	//방법1
	int i = 0;
	for (int j = 0;; i++) {
		if (N < 9 * pow(10, i) + j)
			break;
		j = 9 * pow(10, i);
	}
	for (int j = 1; j <= i; j++) {
		sum += j * 9 * pow(10, j-1);
	}
	sum += (N - pow(10, i) + 1)* (i+1);
	*/

	//방법 2
	for (int i = 1; i <= N; i *= 10) {
		sum += N - i + 1;
	}

	cout << sum;
}

