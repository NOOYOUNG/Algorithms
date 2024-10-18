#include <iostream>
using namespace std;

int main() {
	int H, W, N, M;
	cin >> H >> W >> N >> M;

	int rows = (H + N) / (N + 1);
	int cols = (W + M) / (M + 1);

	int sum = rows * cols;
	cout << sum;
	return 0;
}