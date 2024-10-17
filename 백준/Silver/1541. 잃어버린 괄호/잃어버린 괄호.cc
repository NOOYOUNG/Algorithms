#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	string str;
	cin >> str;

	int answer = 0;
	string num = "";
	bool isMinus = false;

	for (int i = 0; i <= str.length(); i++) {
		if (str[i] == '-' || str[i] == '+' || i == str.length()) {
			if (isMinus == true) {
				answer -= stoi(num);
				num = "";
			}
			else if (isMinus == false) {
				answer += stoi(num);
				num = "";
			}
		}
		else {
			num += str[i];
		}

		if (str[i] == '-') {
			isMinus = true;
		}
	}
	cout << answer;
	return 0;
}