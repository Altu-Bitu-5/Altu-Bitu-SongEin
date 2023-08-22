#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}


int main() {
	int t, n;
	cin >> t;
	int s1, s2, k, les = 1, max = 1;
	vector<int> v(t);

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<pair<int, int>> s; //vector 페어 사용

		for (int j = 0; j < n; j++) {
			cin >> s1 >> s2;
			if (s2 == 1) { // 면접 심사 1등의 서류 심사 순위를 les에 저장
				les = s1;
			}
			s.push_back(make_pair(s1, s2));
		}
		sort(s.begin(), s.end(), comp); //오름차순 정렬
		k = s[0].second;

		for (int j = 0; j < les; j++) { // 서류 심사 1등부터 면접 심사 1등 사이에 있는 인원을 확인
			if (s[j].second < k) { // 서류 심사 1등의 면접 심사 순위보다 높을 경우 선발.
				max++;
				k = s[j].second;
			}
		}
		v[i] = max;
		max = 1;
	}
	for (int i = 0; i < t; i++) {
		cout << v[i] << endl;
	}
}