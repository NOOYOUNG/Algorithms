#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	cin >> M;
	vector<int> lamp(M);
	for (int i = 0; i < M; i++) {
		cin >> lamp[i];
	}

	sort(lamp.begin(), lamp.end());

	int left = 1;
	int right = N;
	int result = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		bool check = (lamp[0] - mid <= 0);

		for (int i = 1; i < M && check; i++) {
			if (lamp[i - 1] + mid < lamp[i] - mid) {
				check = false;
			}
		}

		if (check && lamp[M - 1] + mid >= N) {
			result = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result;

	return 0;
}