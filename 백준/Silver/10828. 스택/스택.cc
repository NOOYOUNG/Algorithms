#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	int N;
	cin >> N;
	stack<int> st;

	for(int i=0; i<N; i++) {
		string A;
		/*getline(cin, A);

		if (A.substr(0, 4) == "push") {
			int num = stoi(A.substr(5));
			st.push(num);
		}*/
		cin >> A;
		if (A == "push") {
			int num;
			cin >> num;
			st.push(num);
		}
		else if (A == "top") {
			if (!st.empty()) {
				cout << st.top() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (A == "size") {
			cout << st.size() << endl;
		}
		else if (A == "empty") {
			if (st.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (A == "pop") {
			if (!st.empty()) {
				cout << st.top() << endl;
				st.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
	}

	return 0;
}