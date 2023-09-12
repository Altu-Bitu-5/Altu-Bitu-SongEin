#include <iostream>
#include <unordered_map>
int const bi_all = 2097150; // 1111 1111 1111 1111 1111
int const bi_empty = 0;

using namespace std;

void cal(string s, int& ans) {
	int n;

	if (s == "add") {
		cin >> n;
		ans |= (1 << n);
	}
	else if (s == "remove") {
		cin >> n;
		ans &= ~(1 << n);
	}
	else if (s == "check") {
		cin >> n;
		if ((ans & (1 << n)) != 0) {
			cout << 1 << "\n";
		}
		else {
			cout << 0 << "\n";
		}
	}
	else if (s == "toggle") {
		cin >> n;
		ans ^= (1 << n);
	}
	else if (s == "all") {
		ans |= bi_all;
	}
	else if (s == "empty") {
		ans &= bi_empty;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int m, c, ans;
	string s;
	ans = 0;


	//입력
	cin >> m;
	
	//연산
	for (int i = 0; i < m; i++) {
		cin >> s;
		cal(s, ans);
	}
}