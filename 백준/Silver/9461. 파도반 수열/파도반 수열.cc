#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<long long> dp(101);
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		for (int i = 5; i <= N; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << '\n';
	}
	return 0;
}
