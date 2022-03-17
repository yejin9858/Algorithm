#include<iostream>
#include<math.h>
using namespace std;

int number[50];
long long loc_x, loc_y;

pair<long long, long long > findLocation(long long start_x, long long start_y, long long end_x, long long end_y, int index) {
	long long length = (end_x - start_x + 1) / 2;

	if (length == 0) {
		return { start_x, start_y };
	}

	long long mid_x = end_x - length;
	long long mid_y = end_y - length;

	switch (number[index])
	{
	case 1:
		return findLocation(mid_x + 1, start_y, end_x, mid_y, index + 1);
	case 2:
		return findLocation(start_x, start_y, mid_x, mid_y, index + 1);
	case 3:
		return findLocation(start_x, mid_y + 1, mid_x, end_y, index + 1);
	case 4:
		return findLocation(mid_x + 1, mid_y + 1, end_x, end_y, index + 1);
	}
}

void findAnswer(long long start_x, long long  start_y, long long end_x, long long  end_y, long long  index) {
	long long  length = (end_x - start_x + 1) / 2;

	if (length == 0) {
		return;
	}

	long long  mid_x = end_x - length;
	long long  mid_y = end_y - length;

	if (loc_x > mid_x && loc_y <= mid_y) {
		number[index] = 1;
		findAnswer(mid_x + 1, start_y, end_x, mid_y, index + 1);
	}
	else if (loc_x <= mid_x && loc_y <= mid_y) {
		number[index] = 2;
		findAnswer(start_x, start_y, mid_x, mid_y, index + 1);
	}
	else if (loc_x <= mid_x && loc_y > mid_y) {
		number[index] = 3;
		findAnswer(start_x, mid_y + 1, mid_x, end_y, index + 1);
	}
	else {
		number[index] = 4;
		findAnswer(mid_x + 1, mid_y + 1, end_x, end_y, index + 1);
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int d;
	long long x, y;
	string str;

	cin >> d >> str >> x >> y;

	int i = 0;
	for (int n : str) {
		number[i] = n - 48;
		if (number[i] != 1 && number[i] != 2 && number[i] != 3 && number[i] != 4) {
			cout << -1;
			return 0;
		}
		i++;
	}

	pair<long long, long long> location = findLocation(1, 1, pow(2, d), pow(2, d), 0);

	loc_x = location.first + x;
	loc_y = location.second - y;

	if (loc_x > pow(2, d) || loc_y > pow(2, d) || loc_x <= 0 || loc_y <= 0) {
		cout << -1;
		return 0;
	}

	findAnswer(1, 1, pow(2, d), pow(2, d), 0);

	for (int i = 0; i < d; i++) {
		cout << number[i];
	}

	return 0;
}