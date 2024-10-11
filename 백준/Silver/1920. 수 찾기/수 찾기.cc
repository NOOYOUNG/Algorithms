#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		long long num;
		cin >> num;
		
		if (binary_search(v.begin(), v.end(), num)) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}

	return 0;
}