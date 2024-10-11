#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int j = 0; j < N; j++) {
			int importance;
			cin >> importance;
			q.push({ importance, j });
			pq.push(importance);
		}
		int ans = 1;

		while (1) {
			int importance = q.front().first;
			int idx = q.front().second;
			if (importance != pq.top()) {
				q.pop();
				q.push({ importance, idx });
			}
			else {
				if (idx == M) break;
				else {
					q.pop();
					pq.pop();
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;	
}