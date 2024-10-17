#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int C;
		cin >> C;
		int q = 0;
		int d = 0;
		int n = 0;
		int p = 0;

		q = C / 25;
		C = C % 25;

		d = C / 10;
		C = C % 10;

		n = C / 5;
		C = C % 5;

		p = C;
	
		cout << q << " " << d << " " << n << " " << p << '\n';
	}
	return 0;
}