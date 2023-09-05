#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool roll(int t, char a, vector<pair<char, bool>> &v, unordered_set<char> &s) {
	
	if ((v[t].second && (v[t].first != a) || (!v[t].second && s.find(a) != s.end()))) { // 기존 항목과 충돌하였거나 알파벳이 중복으로 쓰였는지 확인
		return false;
	}
	else {
		v[t].first = a;
		v[t].second = true;
		s.insert(a);
		return true;
	}
}

int main() {
	int n, k, t, r;
	char a;
	bool b = true;
	unordered_set<char> s;
	t = 0;

	//입력
	cin >> n >> k;
	vector<pair<char, bool>> v(n, {'?', false});

	//연산
	for (int i = 0; i < k; i++) {
		cin >> r >> a;
		if (!b) {
			continue;
		}
		t = (t + r) % n;
		b = roll(t, a, v, s);
;	}

	//출력-> 마지막 위치부터 시계방향으로
	if (b) {
		for (int i = n; i > 0; i--) {
			cout << v[(t + i) % n].first;
		}
	}
	else {
		cout << "!";
	}
}