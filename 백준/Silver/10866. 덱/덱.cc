#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N;
	cin >> N;
	deque<int> dq;
	for (int i = 0; i < N; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "push_front") {
			int num;
			cin >> num;
			dq.push_front(num);
		}
		else if (cmd == "push_back") {
			int num;
			cin >> num;
			dq.push_back(num);
		}
		else if (cmd == "pop_front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << endl;
				dq.pop_front();
			}
		}
		else if (cmd == "pop_back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << endl;
				dq.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << dq.size() << endl;
		}
		else if (cmd == "empty") {
			if (dq.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (cmd == "front") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.front() << endl;
			}
		}
		else if (cmd == "back") {
			if (dq.empty()) {
				cout << "-1\n";
			}
			else {
				cout << dq.back() << endl;
			}
		}
	}
}