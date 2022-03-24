#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int A, B; 
bool findAnswer = false;

void calculateAnswer(int c, vector<int> now) {
	if (findAnswer) return;
	else if (now.size() == 0) {
		if (c < B) {
			cout << c;
			findAnswer = true;
			return;
		}
	}
	c *= 10;
	for (int i = 0; i < now.size(); i++) {
		if (c == 0 && now.at(i) == 0) continue;
		int subA = c;
		vector<int> subNow = now;
		subA += subNow.at(i);
		subNow.erase(subNow.begin() + i);
		calculateAnswer(subA, subNow);
	}
}

int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	int answer = 1;

	cin >> A >> B;

	vector<int> As;

	while (A != 0) {
		As.push_back(A % 10);
		A /= 10;
	}

	sort(As.begin(), As.end(), greater<>());

	calculateAnswer(0, As);

	if(!findAnswer)
		cout << -1;
	return 0;
}