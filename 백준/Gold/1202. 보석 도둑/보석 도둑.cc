#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	vector<pair<long long, long long>> jewel(N);
	vector<long long> bag(K);

	for (int i = 0; i < N; i++) {
		cin >> jewel[i].first >> jewel[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}

	priority_queue<long long> pq;
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	long long sum = 0;
	int idx = 0;
	for (int i = 0; i < K; i++) {
		int weight = bag[i];
		while (idx < N && jewel[idx].first <= weight) {
			pq.push(jewel[idx].second);
			idx++;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum;
	
	return 0;
}