#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
vector<int> visited;

int bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int curback = cur - 1;
		int curfront = cur + 1;
		int curmulti = cur * 2;

		if (curback >= 0 && visited[curback] == -1) {
			q.push(curback);
			visited[curback] = visited[cur] + 1;
		}

		if (curfront <= 100000 && visited[curfront] == -1) {
			q.push(curfront);
			visited[curfront] = visited[cur] + 1;
		}

		if (curmulti <= 100000 && visited[curmulti] == -1) {
			q.push(curmulti);
			visited[curmulti] = visited[cur] + 1;
		}

		if (cur == K) {
			return visited[cur];
		}
	}
}

int main() {
	cin >> N >> K;

	visited.assign(100001, -1);

	int ans = bfs();
	cout << ans;

	return 0;
}
