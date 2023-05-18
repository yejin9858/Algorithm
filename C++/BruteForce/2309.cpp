#include <iostream>
using namespace std;
/*
//방법 1
bool t[101];
int d[10];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int sum = 0;
	
	for (int i = 1; i <= 9; i++) {
		cin >> d[i];
		sum += d[i];
		t[d[i]] = true;
	}

	for (int i = 1; i < 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (sum - d[i] - d[j] == 100) {
				t[d[i]] = false;
				t[d[j]] = false;
				for (int i = 1, count = 0; i <= 100; i++) {
					if (t[i]) {
						cout << i << "\n";
						count++;
					}
					if (count == 7)
						break;
				}
				return 0;
			}
		}
	}
}
*/

int dwarf[9];
//방법2	
void find100(int height);
void setOrder();

int main() {
	ios::sync_with_stdio;
	cin.tie(0);

	int height = 0;

	for (int i = 0; i < 9; i++) {
		cin >> dwarf[i];
		height += dwarf[i];
	}

	find100(height);
	setOrder();

	for (int i = 2; i < 9; i++)
		cout << dwarf[i] << "\n";
}

void find100(int height) {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (height - dwarf[i] - dwarf[j] == 100) {
				dwarf[i] = 0;
				dwarf[j] = 0;
				return;
			}
		}
	}
}

void setOrder() {
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (dwarf[i] > dwarf[j]) {
				int tmp = dwarf[i];
				dwarf[i] = dwarf[j];
				dwarf[j] = tmp;
			}
		}
	}
}
	