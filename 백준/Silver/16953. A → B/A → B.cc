#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	int cnt = 1;
	while (A < B) {
		if (B % 2 == 0) {
			B /= 2;
		}
		else if (B % 10 == 1) {
			B /= 10;
		}
		else {
			break;
		}
		cnt++;
	}
	if (B == A) {
		cout << cnt;
	}
	else {
		cout << "-1";
	}
	return 0;
}
