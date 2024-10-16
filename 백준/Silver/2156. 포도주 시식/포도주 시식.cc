#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	
	vector<int> dp(n + 1);
	dp[1] = v[1];
	if (n > 1) {
		dp[2] = v[1] + v[2];
	}

	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 1], // i번째 잔을 선택하지 않는 경우
					max(dp[i - 2] + v[i], // i번째 잔을 선택하는 경우
						dp[i - 3] + v[i] + v[i - 1])); // i번째와 (i-1)번째 잔을 선택하는 경우
	}
	
	cout << dp[n];
	return 0;
}

/*
dp[3] = max(dp[2], dp[1] + v[3], dp[0] + v[2] + v[3])
	dp[3] = max(16, 6 + 13, 0 + 10 + 13) = max(16, 19, 23) = 23
dp[4] = max(dp[3], dp[2] + v[4], dp[1] + v[3] + v[4])
	dp[4] = max(23, 16 + 9, 6 + 13 + 9) = max(23, 25, 28) = 28
dp[5] = max(dp[4], dp[3] + v[5], dp[2] + v[4] + v[5])
	dp[5] = max(28, 23 + 8, 16 + 9 + 8) = max(28, 31, 33) = 33
dp[6] = max(dp[5], dp[4] + v[6], dp[3] + v[5] + v[6])
	dp[6] = max(33, 28 + 1, 23 + 8 + 1) = max(33, 29, 32) = 33
*/
