#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	map<string, int> names;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		names[name]++;
	}
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		names[name]--;
	}

	vector<string> v;
	for (auto n : names) {
		if (n.second == 0) {
			v.push_back(n.first);
		}
	}

	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0;
}