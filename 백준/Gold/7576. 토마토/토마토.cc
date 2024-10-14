#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int M, N;
vector<vector<int>> boxes;
vector<vector<int>> days;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (boxes[i][j] == 1) { // 익은 토마토가 있는 경우
				q.push({ i,j }); // 큐에 현재 토마토 위치 추가
				days[i][j] = 0; // 익은 토마토의 날짜를 0으로 설정
			}
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 상하좌우로 이동하면서 익지 않은 토마토를 익힘
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) { // 좌표가 범위 안에 있다면
				if (boxes[nx][ny] == 0) { // 익지 않은 토마토인 경우
					boxes[nx][ny] = 1; // 토마토를 익은 상태로 변경
					days[nx][ny] = days[x][y] + 1; // 익는 날짜 기록
					q.push({ nx, ny }); // 큐에 새로운 토마토 위치 추가
				}
			}
		}
	}

	int max_days = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (boxes[i][j] == 0) { // 익지 않은 토마토가 있는 경우
				return -1;
			}
			max_days = max(max_days, days[i][j]);
		}
	}
	return max_days;
}

int main() {
	// M: 상자의 가로 칸 수 (열의 수)
	// N: 상자의 세로 칸 수 (행의 수)
	cin >> M >> N;
	boxes.assign(N, vector<int>(M));
	days.assign(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> boxes[i][j];
		}
	}

	int result = bfs();
	cout << result;
	return 0;
}