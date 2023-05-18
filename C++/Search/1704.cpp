#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>

using namespace std;
int r, c, ans = 0;
int z(int N) {
	if (N == 0)
		return ans;
	int power = pow(2, N - 1);
	if (r < power && c >= power) {
		ans += power * power;
		c -= power;
	}
	else if (r >= power && c < power) {
		ans += power * power * 2;
		r -= power;
	}
	else if (r >= power && c >= power) {
		ans += power * power * 3;
		r -= power; c -= power;
	}
	return z(N - 1);
}

int main() {
	int N;
	cin >> N >> r >> c;
	cout << z(N);
}