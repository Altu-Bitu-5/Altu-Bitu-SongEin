#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarysearch(int sum, int m, vector<int> &lec, int max_length) {
	int left = max_length;
	int right = sum;
	int mid, count, min_lec, temp_dvd;
	min_lec = sum;

	while (left <= right) {
		mid = (left + right) / 2;
		count = 1;
		temp_dvd = 0;

		for (int i = 0; i < lec.size(); i++) { 
			temp_dvd += lec[i]; //일시적으로 강의 길이를 저장
			if (temp_dvd > mid) { //만약 블루레이 길이보다 길면 새로운 블루레이에 기록하고 개수 카운트를 올림
				temp_dvd = lec[i];
				count++;
			}
		}
		if (count <= m) {
			right = mid - 1;
			min_lec = min(mid, min_lec); //카운트가 m보다 작을 경우 나누어 담을 수도 있다는 뜻이기 때문에
		}
		else if (count > m) {
			left = mid + 1;
		}
	}
	return min_lec;
}

int main() {
	//선언
	int n, m, temp, sum = 0, max_length = 0;

	//입력
	cin >> n >> m;
	vector<int> lec(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		sum += temp;
		max_length = max(max_length, temp);
		lec[i] = temp;
	}

	//연산 및 출력
	cout << binarysearch(sum, m, lec, max_length);
}