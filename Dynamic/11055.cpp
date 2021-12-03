#include <string>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

int Du[1001];
int A[1001];
int B[1001];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	int ans = 0;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		Du[i] = A[i];
	}

	int sum = Du[1];
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j]) {
				if (Du[i] < Du[j] + A[i]) {
					B[i] = A[j];
					Du[i] = Du[j] + A[i];
				}
			}
		}
		sum = max(sum, Du[i]);
	}

	cout << sum;


}