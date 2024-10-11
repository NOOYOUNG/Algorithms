#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	int N;
	cin >> N;

	unordered_map<int, int> cards;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		cards[num]++;
	}

	int M;
	cin >> M;
	vector<int> ans;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		ans.push_back(cards[num]);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}