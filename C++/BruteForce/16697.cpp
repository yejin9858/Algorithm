#include<iostream>
#include<math.h>
using namespace std;

int ans = -pow(2,21) , N;
string str;

int calculate(int a, int b, char op) {
	switch (op) {
	case '+': 
		return a + b;
	case '-': 
		return a - b;
	case '*': 
		return a * b;
	}
}

void makePar(int index, int num) {
	if (index >= N) { 
		ans = ans < num ? num : ans;
		return;
	}
	char op = index >= 1 ? str[index - 1] : '+'; 
	int temp = calculate(num, str[index] - '0', op); 
	makePar(index + 2, temp); 

	if (index < N - 2) { 
		temp = calculate(str[index] - '0', str[index + 2] - '0', str[index + 1]);
		temp = calculate(num, temp, op); 
		makePar(index + 4, temp);
	}
}


int main(void) {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);


	cin >> N;
	cin >> str;

	makePar(0, 0);

	cout << ans;

	return 0;

}