#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;

	int zero = 0, one = 0;

	for (int i = 0; i < S.length(); i++) {
		if (S[i] != S[i + 1]) {
			if (S[i] == '0') {
				zero++;
			}
			else if (S[i] == '1') {
				one++;
			}
		}
	}

	cout << min(zero, one);
	return 0;
}