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

		if (sum >= M) { // 잘린 나무의 총 길이가 M보다 크거나 같으면 높이를 더 높여도 되므로 left 조정
			H = mid;
			left = mid + 1;
		}
		else { // 나무가 부족하므로 높이를 낮추기 위해 right 조정
			right = mid - 1;
		}
	}

	cout << H;
	return 0;
}
