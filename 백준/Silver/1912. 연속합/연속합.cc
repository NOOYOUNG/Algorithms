#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> dp(n);
	dp[0] = v[0];
	int sum = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] += max(v[i], v[i] + dp[i - 1]);
		sum = max(sum, dp[i]);
	}

	cout << sum;

	return 0;
}