#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> w(N);
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}

	sort(w.begin(), w.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int currentw = w[i] * (i + 1);
		ans = max(ans, currentw);
	}
	cout << ans;
	return 0;
}