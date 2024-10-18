#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	string game;
	cin >> N >> game;

	vector<string> p(N);
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());

	if (game == "Y") {
		cout << p.size();
	}
	else if (game == "F") {
		cout << p.size() / 2;
	}
	else if (game == "O") {
		cout << p.size() / 3;
	}

	return 0;
}