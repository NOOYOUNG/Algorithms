#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	stack<int> st;
	vector<char> ans;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		while (cnt <= num) {
			st.push(cnt);
			cnt++;
			ans.push_back('+');
		}
		if (st.top() == num) {
			st.pop();
			ans.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}