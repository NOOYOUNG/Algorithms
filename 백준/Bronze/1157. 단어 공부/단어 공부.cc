#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		S[i] = toupper(S[i]);
	}

	map<char, int> alp;
	for (auto s : S) {
		alp[s]++;
	}

	char mostch = '?';
	int maxcnt = 0;
	int chcnt = 0;

	for (auto a : alp) {
		if (a.second > maxcnt) {
			maxcnt = a.second;
			mostch = a.first;
			chcnt = 1;
		}
		else if (a.second == maxcnt) {
			chcnt++;
		}
	}

	if (chcnt > 1) {
		cout << '?';
	}
	else {
		cout << mostch;
	}
	return 0;
}