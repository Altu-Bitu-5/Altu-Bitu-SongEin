#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m, count = 0;
	string s, c;
	set<string> s_set;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;
		s_set.insert(s);
	}
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (s_set.find(c) != s_set.end()) {
			count++;
		}
	}
	cout << count;
}