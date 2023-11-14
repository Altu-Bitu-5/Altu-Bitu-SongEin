#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long binarysearch(vector<long long>& table, int m) {
	long long left = 1;
	long long  right = *max_element(table.begin(), table.end()) * m;
	long long  mid, count, ans;
	ans = right;

	while (left <= right) {
		mid = (left + right) / 2;
		count = 0;

		for (long long i = 0; i < table.size(); i++) {
			count += mid / table[i]; // 시간 내에 각 심사대에서 처리할 수 있는 인원수
			if (count > m) { //count의 오버플로우 방지를 위해 빠르게 탈출하는 코드 추가
				break;
			}
		}
		if (count < m) {
			left = mid + 1;
		}
		else{
			ans = min(mid, ans);
			right = mid - 1;
		}
	}
	return ans;
}

int main() {
	//선언
	long long  n, m;

	//입력
	cin >> n >> m;
	vector<long long> table(n);
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}

	// 연산 및 출력
	cout << binarysearch(table, m);
}