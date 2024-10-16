#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> trees(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
	}

	int left = 0;
	int right = *max_element(trees.begin(), trees.end());
	int H = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0;

		for (auto t : trees) {
			if (t > mid) {
				sum += (t - mid);
			}
		}

		if (sum >= M) {
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