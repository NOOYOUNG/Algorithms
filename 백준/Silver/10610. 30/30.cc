#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string N;
	cin >> N;

	int sum = 0;
	for (auto ch : N) {
		sum += ch - '0';
	}

	if (sum % 3 == 0 && N.find("0") != string::npos) {
		sort(N.begin(), N.end(), greater<char>());
		cout << N;
	}
	else {
		cout << "-1";
	}
	return 0;
}