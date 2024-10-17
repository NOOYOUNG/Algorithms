#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	int a = 0;
	int b = 0;
	int c = 0;
	
	a = T / 300;
	T %= 300;

	b = T / 60;
	T %= 60;
	
	c = T / 10;
	T %= 10;

	if (T != 0) {
		cout << "-1";
		return 0;
	}
	cout << a << " " << b << " " << c;

	return 0;
}