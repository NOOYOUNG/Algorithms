#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int dfs(int v) {
	visited[v] = true;
	int ans = 0;
	for (int i = 0; i < adj[v].size(); i++) {
		if (!visited[adj[v][i]]) {
			ans += 1 + dfs(adj[v][i]);
		}
	}
	return ans;
}

int main() {
	int coms, nodes;
	cin >> coms;
	cin >> nodes;
	adj.resize(coms + 1);
	visited.resize(coms + 1, false);

	for (int i = 0; i < nodes; i++) {
		int v, w;
		cin >> v >> w;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}

	int answer=dfs(1);
	cout << answer;
	return 0;
}