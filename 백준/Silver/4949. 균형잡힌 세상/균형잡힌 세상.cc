#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	while (true) {
		string str;
		getline(cin, str);
		if (str == ".") {
			break;
		}

		bool result = true;

		stack<char> st;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(' || str[i] == '[') { // 여는 괄호 "(", "[" stack에 push 
				st.push(str[i]);
			}

			if (str[i] == ']') {
				if (!st.empty() && st.top() == '[') {
					st.pop();
				}
				else {
					result = false;
					break;
				}
			}
			else if (str[i] == ')') {
				if (!st.empty() && st.top() == '(') {
					st.pop();
				}
				else {
					result = false;
					break;
				}
			}
		}
		if (st.empty() && result) cout << "yes" << '\n';
		else cout << "no" << '\n';
	}
	return 0;
}