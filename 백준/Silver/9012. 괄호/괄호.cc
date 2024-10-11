#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	vector<string> str;
	for (int i = 0; i < T; i++) {
		string A = "";
		cin >> A;
		str.push_back(A);
	}

	for (int i = 0; i < str.size(); i++) {
		stack<char> st;
		
		for (int j = 0; j < str[i].length(); j++) {
			if (st.empty()) {
				st.push(str[i][j]);
			}
			else {
				if (st.top() == '(' && str[i][j] == ')') {
					st.pop();
				}
				else {
					st.push(str[i][j]);
				}
			}
		}

		if (st.empty()) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	return 0;
}