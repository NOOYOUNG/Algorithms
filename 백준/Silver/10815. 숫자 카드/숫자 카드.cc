#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, M;
	cin >> N;
	unordered_set<int> sang;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sang.insert(num);
	}

	cin >> M;
	vector<int> qcards(M);
	for (int i = 0; i < M; i++) {
		cin >> qcards[i];
	
		if (sang.find(qcards[i]) != sang.end()) {
			cout << "1 ";
		}
		else {
			cout << "0 ";
		}
	}

	return 0;
}
