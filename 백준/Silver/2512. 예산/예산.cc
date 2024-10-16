#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> local(N);
	for (int i = 0; i < N; i++) {
		cin >> local[i];
	}

	long long M;
	cin >> M;

	long long left = 0;
	long long right = *max_element(local.begin(), local.end());
	long long answer = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		long long sum = 0;

		for (auto l : local) {
			sum += min(l, mid);
		}

		if (M >= sum) {
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