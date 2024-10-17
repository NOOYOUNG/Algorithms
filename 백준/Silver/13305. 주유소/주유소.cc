#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long long> distance(N - 1);
	vector<long long> city(N);
	for (int i = 0; i < N - 1; i++) {
		cin >> distance[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> city[i];
	}

	long long cost = city[0];
	long long total = 0;

	for (int i = 0; i < N - 1; i++) {
		total += (cost * distance[i]);

		if (city[i+1] < cost) {
			cost = city[i + 1];
		}
	}
	cout << total;
	return 0;
}
