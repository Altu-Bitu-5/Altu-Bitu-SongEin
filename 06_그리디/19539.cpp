#include <iostream>
#include <vector>

using namespace std;

bool apple(vector<int> tree) {
	int sum = 0, count = 0;

	// 2씩 자라는 물뿌리개로 키울 수 있는 것은 1씩 자라는 물뿌리개로도 키울 수 있다.
	// 나무를 키우는 데 걸리는 시간만큼 2씩 물뿌리개를 뿌릴 수 있다면 물뿌리개로 키울 수 있음.

	for (int i = 0; i < tree.size(); i++) {
		sum += tree[i]; // 나무의 총 높이를 구함
		count += tree[i] / 2; // 2짜리 물뿌리개로 뿌릴 수 있는 개수
	}
	if (sum % 3 != 0) { // 높이가 3으로 나누어지지 않을 경우
		return false;
	}
	else if (sum / 3 <= count) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	//선언
	int n, temp, sum;
	bool b;
	sum = 0;

	//입력
	cin >> n;
	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
	}

	//연산
	b = apple(tree);

	//출력
	if (b) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}