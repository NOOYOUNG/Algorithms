#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;

int V, E, K;
vector<vector<pair<int, int>>>graph;
vector<int> dist;

void solution(int start) {
	dist[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,start }); // {거리, 정점} 형태로 시작 정점을 큐에 추가

	while (!pq.empty()) {
		int curDist = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if (curDist > dist[curNode]) continue;

		for (auto g : graph[curNode]) {
			int nextNode = g.first;
			int weight = g.second;

			if (dist[curNode] + weight < dist[nextNode]) {
				dist[nextNode] = dist[curNode] + weight;
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}
}

int main() {
	cin >> V >> E;
	cin >> K;

	graph.assign(V + 1, vector<pair<int, int>>());
	dist.assign(V + 1, INT_MAX);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}

	solution(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	return 0;
}