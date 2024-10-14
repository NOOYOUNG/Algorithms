#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int v) {
	visited[v] = true;
	int answer = 0;
	for (int i = 0; i<adj[v].size(); i++) {
		if (!visited[adj[v][i]]) {
			dfs(adj[v][i]);
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	adj.resize(N + 1);
	visited.resize(N + 1, false);

	for (int i = 0; i < M; i++) {
		int v, w;
		cin >> v >> w;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			dfs(i);
			ans++;
		}
	}

	cout << ans;
	return 0;
}