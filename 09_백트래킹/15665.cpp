#include <iostream>
#include <set>
#include <vector>

using namespace std;

void backtrack(int index, int m, set<int> s, vector<int> ans) {
	//종료 조건
	if (index == m) {
		for (int i = 0; i < m; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		ans[index] = *iter;
		backtrack(index + 1, m, s, ans);
	}
}


int main() {
	//선언
	int n, m, temp;
	set<int> s;

	//입력
	cin >> n >> m;
	vector<int> ans(m);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.insert(temp);
	}

	//연산 및 출력
	backtrack(0, m, s, ans);
}