#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, C;
	cin >> N >> C;

	vector<int> home(N);
	for (int i = 0; i < N; i++) {
		cin >> home[i];
	}

	sort(home.begin(), home.end());

	int left = 1;
	int right = home[N - 1];
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int start = home[0];
		for (int i = 1; i < N; i++) {
			if (home[i] - start >= mid) {
				start = home[i];
				cnt++;
			}
		}
		if (cnt >= C) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer;

	return 0;
}