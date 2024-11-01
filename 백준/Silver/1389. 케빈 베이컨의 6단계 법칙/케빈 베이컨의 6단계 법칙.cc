#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

const int INF = INT_MAX;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N + 1, vector<int>(N + 1, INF));

	for (int i = 1; i <= N; i++) {
		v[i][i] = 0;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a][b] = 1;
		v[b][a] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (v[i][k] != INF && v[k][j] != INF) {
					v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
				}
			}
		}
	}

	vector<int> ans(N+1, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				ans[i] += v[i][j];
			}
		}
	}

	int min = ans[1];
	int index = 1;
	for (int i = 2; i <= N; i++) {
		if (ans[i] < min) {
			min = ans[i];
			index = i;
		}
	}

	cout << index;
	return 0;
}