#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> v;

int bfs(int start, int target) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(N + 1, INT_MAX);
	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int time = pq.top().first;
		int x = pq.top().second;
		pq.pop();

		if (time > dist[x]) continue;

		for (auto i : v[x]) {
			int nextNode = i.first;
			int weight = i.second;
			if (dist[x] + weight < dist[nextNode]) {
				dist[nextNode] = dist[x] + weight;
				pq.push({ dist[nextNode], nextNode });
			}
		}
	}
	return dist[target];
}

int main() {
	cin >> N >> M >> X;
	v.assign(N + 1, vector<pair<int,int>>());
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	int maxTime = 0;
	for (int i = 1; i <= N; i++) {
		if (i == X) continue;
		int toX = bfs(i, X);
		int fromX = bfs(X, i);
		maxTime = max(maxTime, toX + fromX);;
	}
	cout << maxTime;
	return 0;
}