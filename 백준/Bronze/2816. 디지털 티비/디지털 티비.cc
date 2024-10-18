#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> ch(N);

	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> ch[i];
		if (ch[i] == "KBS1") {
			cnt1 = i;
		}
		else if (ch[i] == "KBS2") {
			cnt2 = i;
		}
	}

	for (int i = 0; i < cnt1; i++) {
		cout << "1";
	}
	for (int i = 0; i < cnt1; i++) {
		cout << "4";
	}

	if (cnt1 > cnt2) cnt2 += 1;
	for (int i = 0; i < cnt2; i++) {
		cout << "1";
	}
	for (int i = 0; i < cnt2-1; i++) {
		cout << "4";
	}
	return 0;
}