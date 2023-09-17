#include <iostream>
#include <string>
int const six = 666;

using namespace std;

int main() {
	int count, find, ans;
	ans = 666;
	count = 1;

	//입력
	cin >> find;

	//연산
	while (count != find) {
		ans++;
		if (to_string(ans).find("666") != string::npos) {
			count++;
		}
	}

	//출력
	cout << ans;
}