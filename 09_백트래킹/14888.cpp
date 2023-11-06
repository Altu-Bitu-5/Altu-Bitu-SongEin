#include <iostream>
#include <vector>

using namespace std;

void backtrack(int n, int& min, int& max, vector<int> array, int op[], int result, int index) {
	//종료 조건
	if (index == n) {
		if (result > max) {
			max = result;
		}
		if (result < min) {
			min = result;
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;
			if (i == 0) {
				backtrack(n, min, max, array, op, result + array[index], index + 1);
			}
			else if (i == 1) {
				backtrack(n, min, max, array, op, result - array[index], index + 1);
			}
			else if (i == 2) {
				backtrack(n, min, max, array, op, result * array[index], index + 1);
			}
			else {
				backtrack(n, min, max, array, op, result / array[index], index + 1);
			}
			op[i]++; // 다음 연산자로 넘어가기 전 개수를 초기화
		}
	}

}

int main() {
	//선언
	int n, min, max;
	int op[4] = { 0, 0, 0, 0 }; //연산자
	min = 1000000001;
	max = -1000000001;

	//입력
	cin >> n;
	vector<int> array(n);
	for (int i = 0; i < n; i++) {
		cin >> array[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	//연산
	backtrack(n, min, max, array, op, array[0], 1);

	//출력
	cout << max << "\n" << min;
}