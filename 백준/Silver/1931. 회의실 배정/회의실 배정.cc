  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) { // 종료시간 같으면 시작시간 기준 정렬
		return a.first < b.first;
	}
	return a.second < b.second; // 종료시간 기준 정렬
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> times(N);
	for (int i = 0; i < N; i++) {
		cin >> times[i].first >> times[i].second;
	}
	sort(times.begin(), times.end(), compare);
	
	int end = times[0].second;
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (times[i].first >= end) {
			end = times[i].second;
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}