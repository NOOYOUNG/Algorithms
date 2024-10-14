#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<bool>> visited;
vector<int> ans;
int N;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int x, int y) {
	visited[x][y] = true;
	int home = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 범위 안에 있고, 아직 방문하지 않았으며, 집이 있는 경우 탐색
		if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny] && adj[nx][ny] == 1) {
			home += bfs(nx, ny);
		}
	}
	return home;
}


int main() {
	cin >> N;

	adj.resize(N, vector<int>(N));
	visited.resize(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++) {
		string row="";
		cin >> row;
		for (int j = 0; j < N; j++) {
			adj[i][j] = row[j] - '0'; // '0'과 '1'을 숫자로 변환하여 저장
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adj[i][j]==1 && !visited[i][j]) { // 아직 방문하지 않은 집을 발견한 경우
				int homes = bfs(i, j); // 새로운 단지의 집 개수를 계산
				ans.push_back(homes);
			}
		}
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}