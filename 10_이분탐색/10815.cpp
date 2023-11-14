#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[mid] == target) {
			return 1;
		}
		else if (arr[mid] > target) {
			right = mid - 1;
		}
		else if (arr[mid] < target) {
			left = mid + 1;
		}
	}
	return 0;
}

int main() {

	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, m, temp;

	//가진 숫자 카드 입력
	cin >> n;
	vector<int> ncard(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		ncard[i] = temp;
	}

	sort(ncard.begin(), ncard.end());

	//확인할 숫자 카드
	cin >> m;
	vector<int> ans(m); // 답을 저장할 vector

	//입력 및 연산
	for (int i = 0; i < m; i++) {
		cin >> temp;
		ans[i] = binarySearch(ncard, temp);
	}

	//출력
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}