#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<bool> visited;
int answer = INT_MAX;

int getDistance() {
	int distance = 0;
	for (const auto& house : houses) {
		int hx = house.first, hy = house.second;
		int minDist = INT_MAX;

		for (int i = 0; i < chickens.size(); i++) {
			int cx = chickens[i].first, cy = chickens[i].second;
			int dist = abs(hx - cx) + abs(hy - cy);
			if (visited[i]) {
				minDist = min(minDist, dist);
			}
		}
		distance += minDist;		
	}
	return distance;
}

void dfs(int idx, int count) {
	if (count==M) {
		answer = min(answer, getDistance());
		return;
	}
	// DFS로 백트래킹 수행, 현재 인덱스 이후의 치킨집들 중에서 선택
    	for (size_t i = idx; i < chickens.size(); i++) {
        	if (!visited[i]) { // 선택되지 않은 치킨집이면
            		visited[i] = true; // 해당 치킨집 선택
            		dfs(i + 1, count + 1); // 재귀 호출로 다음 치킨집 선택
            		visited[i] = false; // 선택 해제하고 다음 경우를 탐색
        	}
    	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 1) houses.push_back({ i,j });
			else if (num == 2) chickens.push_back({ i,j });
		}
	}

	visited.assign(chickens.size(), false);
	dfs(0, 0);
	cout << answer;
	return 0;
}
