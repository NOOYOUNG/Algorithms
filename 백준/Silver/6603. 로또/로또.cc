#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<int> v;
void dfs(int idx, int count) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) {
			cout << answer[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		answer.push_back(v[i]);
		dfs(i + 1, count + 1);
		answer.pop_back();
	}
}

int main() {
	int T;
	while (true) {
		cin >> T;
		if (T == 0) break;
		v.resize(T);
		for (int i = 0; i < T; i++) {
			cin >> v[i];
		}

		answer.clear();
		dfs(0, 0);
		sort(answer.begin(), answer.end());
		cout << '\n';
	}
	return 0;
}
