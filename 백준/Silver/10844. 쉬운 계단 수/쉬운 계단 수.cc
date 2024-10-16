#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	long long dp[101][10] = { 0, };
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) { // 마지막 숫자가 0인 경우, 이전 숫자는 반드시 1
				dp[i][j] = dp[i - 1][j + 1];
			}
			else if (j == 9) { // 마지막 숫자가 9인 경우, 이전 숫자는 반드시 8
				dp[i][j] = dp[i - 1][j - 1];
			}
			else { // 2 ~ 8까지는 d - 1, d + 1
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
			dp[i][j] %= 1000000000;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[N][i];
	}

	cout << sum % 1000000000;

	return 0;
}
