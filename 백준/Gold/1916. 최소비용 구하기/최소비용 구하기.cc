#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

const int INF = INT_MAX;
int main() {
	int N, M;
	cin >> N;
	cin >> M;
	vector<vector<pair<int, int>>> v(N + 1);

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	int a, b;
	cin >> a >> b;

	vector<int> dist(N + 1, INF);
	dist[a] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,a }); // {거리, 노드}

	while (!pq.empty()) {
		int curDist = pq.top().first; // 현재 노드까지 거리
		int curNode = pq.top().second; // 현재 노드
		pq.pop();
		if (curDist > dist[curNode]) continue; // 현재 노드까지 거리보다 큰 값이면 무시

		for (auto i : v[curNode]) {
			int nextNode = i.first; // 도착 노드
			int cost = i.second; // 비용

			if (dist[curNode] + cost < dist[nextNode]) {
				dist[nextNode] = dist[curNode] + cost;
				pq.push({ dist[nextNode],nextNode });
			}
		}
	}

	cout << dist[b];
	return 0;
}