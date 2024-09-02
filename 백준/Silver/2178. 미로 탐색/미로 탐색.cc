#include <iostream>
#include <queue>

using namespace std;

string map[100];
int N, M;
int dist[100][100];
int dx[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void BFS(int x, int y) {
	q.push(make_pair(x, y));
	dist[x][y] = 1; // 시작점의 거리 설정

	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && dist[nx][ny] == 0 && map[nx][ny] == '1') { // 미로 안에 있는 경우
				q.push(make_pair(nx, ny)); // queue에 push
				dist[nx][ny] = dist[x][y] + 1; // 거리 업데이트
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	BFS(0, 0); // (0,0)에서 BFS 시작
	cout << dist[N - 1][M - 1];
}