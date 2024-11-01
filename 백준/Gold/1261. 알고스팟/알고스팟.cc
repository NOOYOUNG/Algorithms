#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int dist[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dist[0][0] = 0;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

			if (map[nx][ny] == 1) {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
			else if (map[nx][ny] == 0) {
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			map[i][j] = ch - '0';
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = INT_MAX;
		}
	}

	bfs();
	cout << dist[M - 1][N - 1];
	return 0;
}