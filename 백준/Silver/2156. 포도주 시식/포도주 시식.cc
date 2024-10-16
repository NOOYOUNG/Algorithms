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
