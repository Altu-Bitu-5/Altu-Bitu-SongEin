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
		vector<pair<int, int>> s; //vector ��� ���

		for (int j = 0; j < n; j++) {
			cin >> s1 >> s2;
			if (s2 == 1) { // ���� �ɻ� 1���� ���� �ɻ� ������ les�� ����
				les = s1;
			}
			s.push_back(make_pair(s1, s2));
		}
		sort(s.begin(), s.end(), comp); //�������� ����
		k = s[0].second;

		for (int j = 0; j < les; j++) { // ���� �ɻ� 1����� ���� �ɻ� 1�� ���̿� �ִ� �ο��� Ȯ��
			if (s[j].second < k) { // ���� �ɻ� 1���� ���� �ɻ� �������� ���� ��� ����.
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