#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> maps;
vector<vector<int>> tmp;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j]==2) { // 바이러스가 있는 곳을 큐에 넣기
				q.push({ i,j });
			}
		}
	}
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (tmp[nx][ny] == 0) {
					tmp[nx][ny] = 2;
					q.push({ nx, ny });
				}
			}
		}
	}
}

int getSafeArea() {
	int Area = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) {
				Area++;
			}
		}
	}
	return Area;
}

int dfs(int wall) {
	if (wall == 3) {
		tmp.assign(maps.begin(), maps.end());
		bfs();
		return getSafeArea();
	}

	int maxSafeArea = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (maps[i][j] == 0) {
				maps[i][j] = 1;
				maxSafeArea = max(maxSafeArea, dfs(wall + 1));
				maps[i][j] = 0;
			}
		}
	}
	return maxSafeArea;
}

int main() {
	cin >> N >> M;

	maps.assign(N, vector<int>(M));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maps[i][j];
		}
	}

	int answer = dfs(0); // 벽 0개 세운 상태에서 시작
	cout << answer;

	return 0;
}