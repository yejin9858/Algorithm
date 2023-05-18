#include <queue>
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int apt[25][25];
int house[313];
void quicksort(int left, int right) {
	int pivot, i, j, temp;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = house[left];
		do {
			do { i++; } while (house[i] < pivot && i <= right);
			do { j--; } while (house[j] > pivot && j >= left);
			if (i < j) {
				temp = house[i];
				house[i] = house[j];
				house[j] = temp;
			}
		} while (i < j);
		temp = house[left];
		house[left] = house[j];
		house[j] = temp;
		quicksort(left, j - 1);
		quicksort(j + 1, right);
	}
}
int main() {
	ios::sync_with_stdio;
	cin.tie(0); cout.tie(0);
	queue<pair<int, int>> Q;
	int N, group = -1, p, q;
	string str;
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		int j = 0;
		for (char c : str) {
			apt[i][j++] = c - 48;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (apt[i][j] == 1) {
				house[++group]++;
				Q.push({ i,j });
				apt[i][j] = 0;
				while (!Q.empty()) {
					p = Q.front().first;
					q = Q.front().second;
					for (int k = 0; k < 4; k++) {
						if (p + dx[k] >= 0 && q + dy[k] >= 0 && p + dx[k] < N && q + dy[k] < N) {
							if (apt[p + dx[k]][q + dy[k]] == 1) {
								Q.push({ p + dx[k],q + dy[k] });
								apt[p + dx[k]][q + dy[k]] = 0;
								house[group]++;
							}
						}
					}
					Q.pop();
				}
			}
		}
	}
	cout << group + 1 << "\n";
	quicksort(0, group);
	for (int i = 0; i <= group; i++)
		cout << house[i] << "\n";
}