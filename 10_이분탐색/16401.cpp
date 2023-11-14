#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int> &cookie, int kid) {
	int left = 1;
	int right = cookie.back();
	int mid, count, max_len;
	max_len = 0;

	while (left <= right) {
		mid = (left + right) / 2;
		count = 0;

		if (mid != 0) {
			for (int i = 0; i < cookie.size(); i++) {
				count += cookie[i] / mid;
			}
		}
		if (count >= kid) {
			left = mid + 1;
			max_len = mid;
		}
		else if (count < kid) {
			right = mid - 1;
		}
	}
	return max_len;
}

int main() {

	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int m, n;

	//입력
	cin >> m >> n;
	vector<int> cookie(n);
	for (int i = 0; i < n; i++) {
		cin >> cookie[i];
	}

	//연산
	sort(cookie.begin(), cookie.end()); // 정렬

	//출력
	cout << find(cookie, m);
}