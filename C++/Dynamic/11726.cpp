#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int d[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;

	cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 1; i < n - 1; i++) {
		d[i + 2] = (d[i] + d[i + 1]) % 10007;
	}

	cout << d[n];

	return 0;
}

/*int fact(long long n);

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int sum = 1;

	cin >> n;

	for (int i = 2; i <= n; i += 2) {
		sum += (fact(n - i / 2) / (fact(n - i) * fact(i / 2))) % 10007;
	}

	cout << sum;
	return 0;
}

int fact(long long n) {
	if (n == 1 || n== 0)
		return 1;
	else if(n * fact(n - 1) ){
		return n * fact(n - 1);
	}
}*/