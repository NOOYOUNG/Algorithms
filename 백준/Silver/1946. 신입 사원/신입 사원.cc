#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<pair<int, int>> p(N);
		for (int i = 0; i < N; i++) {
			cin >> p[i].first >> p[i].second;
		}
		sort(p.begin(), p.end());

		int maxscore = p[0].second;
		int cnt = 1;
		for (int i = 0; i < N; i++) {
			if (p[i].second < maxscore) {
				cnt++;
				maxscore = p[i].second;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}