#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	vector<int> lines(K);
	for (int i = 0; i < K; i++) {
		cin >> lines[i];
	}

	long long left = 1;
	long long right = *max_element(lines.begin(), lines.end());
	long long H = 0;
	while (left<=right) {
		long long mid = (left + right) / 2;
		long long count = 0;

		for (auto l : lines) {
			count += (l / mid);
		}

		if (count >= N) {
			H = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

	}
	cout << H;
	return 0;
}
