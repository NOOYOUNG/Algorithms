#include <iostream>

using namespace std;

long long dp(int n, int r) {
	if (n < r) {
		return 0;
	}
	if (n == r || r == 0) {
		return 1;
	}
	if (r > n - r) {
		r = n - r;
	}

	long long result = 1;
	for (int i = 0; i < r; i++) {
		result *= (n - i); 
		result /= (i + 1); 
	}
	return result;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout << dp(M, N) << '\n';  // M개 중 N개 선택
	}
	return 0;
}
