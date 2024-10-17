#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	long long S;
	cin >> S;

	int i = 1;
	int cnt = 0;
	while (S >= 0) {
		S -= i;
		if (S < 0) break;
		i++;
		cnt++;
	}
	cout << cnt;
	return 0;
}