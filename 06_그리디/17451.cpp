#include <iostream>
#include <vector>

using namespace std;

long long minSpeed(vector<int>& speed_for) {
	long long  min_speed = speed_for[speed_for.size()-1];

	for (int i = speed_for.size() - 2; i >= 0 ; i--) { // 뒤쪽에서부터 탐색
		if (speed_for[i] > min_speed) { // 속도가 부족할 경우
			min_speed = speed_for[i];
		}
		else if (min_speed % speed_for[i] != 0) { // 배수가 아닐 경우
			min_speed = speed_for[i] * (min_speed / speed_for[i] + 1);
		}
	}
	return min_speed;
}

int main() {
	//선언
	int n;
	long long speed;

	//입력
	cin >> n;
	vector<int> speed_for(n);

	for (int i = 0; i < n; i++) {
		cin >> speed_for[i];
	}

	//연산
	speed = minSpeed(speed_for);

	//출력
	cout << speed;
}