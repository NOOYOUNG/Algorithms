#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	int N;
	cin >> N;
	queue<int> q;

	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int num;
			cin >> num;
			q.push(num);
		}
		else if (cmd == "pop") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (cmd == "size") {
			cout << q.size() << endl;
		}
		else if (cmd == "empty") {
			if (q.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cmd == "front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << endl;
			}
		}
		else if (cmd == "back") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << endl;
			}
		}
	}

	return 0;
}