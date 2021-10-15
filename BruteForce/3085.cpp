#include<iostream>
using namespace std;

char A[50][50];
int ans;
int N;

void check();

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;
		strcpy_s(A[i], row.c_str());
	}

	//행 바꾸기
	for (int i = 0; i < N ; i++) {
		for (int j = 0; j < N - 1; j++) {
			swap(A[i][j], A[i][j + 1]);
			check();
			swap(A[i][j], A[i][j + 1]);
		}
	}

	//열 바꾸기
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			swap(A[i][j], A[i + 1][j]);
			check();
			swap(A[i][j], A[i + 1][j]);
		}
	}

	cout << ans;

}

void check() {
	for (int i = 0; i < N; i++) {
		int count = 1;
		char old = A[i][0];
		for (int j = 1; j < N; j++) {
			if (A[i][j] == old)
				count++;
			else {
				ans = max(count, ans);
				count = 1;
			}
			old = A[i][j];
		}
		ans = max(count, ans);
	}

	for (int j = 0; j < N; j++) {
		int count = 1;
		char old = A[0][j];
		for (int i = 1; i < N; i++) {
			if (A[i][j] == old)
				count++;
			else {
				ans = max(count, ans);
				count = 1;
			}
			old = A[i][j];
		}
		ans = max(count, ans);
	}
}