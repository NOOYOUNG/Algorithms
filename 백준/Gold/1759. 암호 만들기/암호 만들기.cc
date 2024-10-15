#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> alp;
int L, C;
vector<string> ans;

bool check(string& str) {
	int moum = 0;
	for (auto ch : str) {
		if (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u') moum++;
	}
	
	if (moum >= 1 && L - moum >= 2) return true;
	return false;
}

void solution(int idx, string str) {
	if (str.length() == L) {
		if (check(str)) {
			ans.push_back(str);
		}
		return;
	}
	
	for (int i = idx; i < alp.size(); i++) {
		solution(i + 1, str + alp[i]);
	}
}

int main() {
	cin >> L >> C;
	alp.resize(C);
	for (int i = 0; i < C; i++) {
		cin >> alp[i];
	}
	sort(alp.begin(), alp.end());

	solution(0, "");
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}