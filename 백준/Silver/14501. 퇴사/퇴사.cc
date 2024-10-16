#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; i++) {
		int T, P;
		cin >> T >> P;

		if (i + T - 1 <= N) {
			dp[i + T - 1] = max(dp[i + T - 1], dp[i - 1] + P);
		}

		dp[i] = max(dp[i], dp[i - 1]);
	}
	cout << dp[N];
	return 0;
}