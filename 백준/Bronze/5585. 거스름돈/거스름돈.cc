#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int money;
	cin >> money;

	int remain = 1000 - money;

	int cnt = 0;

	cnt += remain / 500;
	remain = remain % 500;

	cnt += remain / 100;
	remain = remain % 100;

	cnt += remain / 50;
	remain = remain % 50;

	cnt += remain / 10;
	remain = remain % 10;

	cnt += remain / 5;
	remain = remain % 5;

	cnt += remain;

	cout << cnt;
	return 0;
}