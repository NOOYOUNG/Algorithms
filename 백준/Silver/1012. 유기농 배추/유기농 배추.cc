#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
vector<vector<int>> maps;
vector<vector<bool>> visited;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && maps[nx][ny] == 1) {
			bfs(nx, ny);
		}
	}
}

int main() {
	int T;
	cin >> T;

	while (T--) {
		cin >> M >> N >> K;

		maps.assign(M, vector<int>(N, 0));
		visited.assign(M, vector<bool>(N, false));
		
		for (int i = 0; i < K; i++) {
			int v, w;
			cin >> v >> w;
			maps[v][w] = 1;
		}

		int worm = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (maps[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					worm++;
				}
			}
		}

		cout << worm << '\n';
	}
	return 0;
}