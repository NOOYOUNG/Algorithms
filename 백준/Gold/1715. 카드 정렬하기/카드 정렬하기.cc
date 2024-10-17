#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		pq.push(num);
	}

	long long sum = 0;
	while (pq.size() > 1) { // 카드 묶음이 1개 남을 때까지 합치기
		long long first = pq.top();
		pq.pop();
		long long second = pq.top();
		pq.pop();
		long long card = first + second;
		pq.push(card);
		sum += card;
	}
	cout << sum;
	return 0;
}