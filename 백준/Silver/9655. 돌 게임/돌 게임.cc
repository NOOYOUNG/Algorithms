#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;

	int dp[1001];
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= N; i++) {
		dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
	}
	if (dp[N] % 2 == 1) { // 홀수면 상근
		cout << "SK";
	}
	else { // 짝수면 창영
		cout << "CY";
	}

	return 0;
}