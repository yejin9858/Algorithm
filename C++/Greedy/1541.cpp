#include<iostream>
#include<queue>
using namespace std;

queue<char> op;
queue<int> number;

bool allMinus = true;
bool allPlus = true;

void exprHandler(string expr) {

	for (int i = 0; i < expr.size(); i++) {
		char c = expr[i];

		if (c == '+' || c == '-') {
			op.push(c);
			if (c == '+') allMinus = false;
			if (c == '-') allPlus = false;
		}
		else if (c >= 48 && c <= 57) {
			int num = c - 48;
			while (expr[i + 1] >= 48 && expr[i + 1] <= 57) {
				num *= 10;
				num += expr[i + 1] - 48;
				i++;
			}
			number.push(num);
		}
	}
}

int simpleCalculate() {
	int ans = number.front();
	number.pop();

	if (allMinus) {
		while (!number.empty()) {
			ans -= number.front();
			number.pop();
		}
	}
	else {
		while (!number.empty()) {
			ans += number.front();
			number.pop();
		}
	}

	return ans;
}

int complexCalculate() {
	char operation;
	int ans = number.front();
	number.pop();

	while (!number.empty()) {
		operation = op.front();
		int num = number.front();
		op.pop();
		number.pop();
		if (operation == '+') {
			ans += num;
		}
		else {
			while (!op.empty()) {
				if (op.front() == '+') {
					num += number.front();
					op.pop();
					number.pop();
				}
				else
					break;
			}
			ans -= num;
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	string expr;
	cin >> expr;
	
	exprHandler(expr);

	if (allMinus || allPlus)
		cout << simpleCalculate();
	else {
		cout << complexCalculate();
	}
}