#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	int K;
	cin >> K;
	stack<int> st;
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		if (num == 0 && !st.empty()) {
			st.pop();
		}
		else if (num != 0) {
			st.push(num);
		}
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << endl;
	return 0;
}