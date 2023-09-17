#include <iostream>

using namespace std;

// 0부터 7까지 8개의 위치
int const MAX = 7; // 최대치
int const MIN = 0; // 최소치
typedef pair<int, int> pos; // 좌표를 지정할 페어 타입

void move(string m, pos& k, pos& r) {
	if (m == "R") {
		k.first++; //킹을 오른쪽으로 한 칸 움직임
		if (k.first > MAX) { // 최대치보다 좌표값이 커지면 (이동 실패)
			k.first--; //이동 취소
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.first++; // 돌을 오른쪽으로 한 칸 움직임
			if (r.first > MAX) { // 최대치보다 좌표값이 커지면 (이동 실패)
				k.first--; //이동 취소
				r.first--;
			}
		}
	}
	else if (m == "L") {
		k.first--; //킹을 왼쪽으로 한 칸 움직임
		if (k.first < MIN) { // 최소치보다 좌표값이 작아지면 (이동 실패)
			k.first++; //이동 취소
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.first--; // 돌을 왼쪽으로 한 칸 움직임
			if (r.first < MIN) { // 최소치보다 좌표값이 작아지면 (이동 실패)
				k.first++; //이동 취소
				r.first++;
			}
		}
	}
	else if (m == "T") {
		k.second++; //킹을 위쪽으로 한 칸 움직임
		if (k.second > MAX) { // 최대치보다 좌표값이 커지면 (이동 실패)
			k.second--; //이동 취소
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.second++; // 돌을 위쪽으로 한 칸 움직임
			if (r.second > MAX) { // 최대치보다 좌표값이 커지면 (이동 실패)
				k.second--; //이동 취소
				r.second--;
			}
		}
	}
	else if (m == "B") {
		k.second--; //킹을 아래쪽으로 한 칸 움직임
		if (k.second < MIN) { // 최소치보다 좌표값이 작아지면 (이동 실패)
			k.second++; //이동 취소
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.second--; // 돌을 아래쪽으로 한 칸 움직임
			if (r.second < MIN) { // 최소치보다 좌표값이 작아지면 (이동 실패)
				k.second++; //이동 취소
				r.second++;
			}
		}
	}
	else if (m == "RT") {
		k.first++; //킹을 움직임
		k.second++;
		if (k.first > MAX || k.second > MAX) { // 좌표값이 범위를 벗어나면 (이동 실패)
			k.first--; //이동 취소
			k.second--;
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.first++; // 돌을 움직임
			r.second++;
			if (r.first > MAX || r.second > MAX) { // 좌표값이 범위를 벗어나면 (이동 실패)
				k.first--; //이동 취소
				k.second--;
				r.first--;
				r.second--;
			}
		}
	}
	else if (m == "LT") {
		k.first--; //킹을 움직임
		k.second++;
		if (k.first < MIN || k.second > MAX) { // 좌표값이 범위를 벗어나면 (이동 실패)
			k.first++; //이동 취소
			k.second--;
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.first--; // 돌을 움직임
			r.second++;
			if (r.first < MIN || r.second > MAX) { // 좌표값이 범위를 벗어나면 (이동 실패)
				k.first++; //이동 취소
				k.second--;
				r.first++;
				r.second--;
			}
		}
	}
	else if (m == "RB") {
		k.first++; //킹을 움직임
		k.second--;
		if (k.first > MAX || k.second < MIN) { // 좌표값이 범위를 벗어나면 (이동 실패)
			k.first--; //이동 취소
			k.second++;
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.first++; // 돌을 움직임
			r.second--;
			if (r.first > MAX || r.second < MIN) { // 좌표값이 범위를 벗어나면 (이동 실패)
				k.first--; //이동 취소
				k.second++;
				r.first--;
				r.second++;
			}
		}
	}
	else if (m == "LB") {
		k.first--; //킹을 움직임
		k.second--;
		if (k.first < MIN || k.second < MIN) { // 좌표값이 범위를 벗어나면 (이동 실패)
			k.first++; //이동 취소
			k.second++;
		}
		else if (k == r) { // 만약 킹을 움직이는 것에 성공했지만 돌의 위치가 겹쳤을 때
			r.first--; // 돌을 움직임
			r.second--;
			if (r.first < MIN || r.second < MIN) { // 좌표값이 범위를 벗어나면 (이동 실패)
				k.first++; //이동 취소
				k.second++;
				r.first++;
				r.second++;
			}
		}
	}
}

int main() {
	//선언
	string king, rock, m; //킹의 위치, 돌의 위치, 움직이는 명령
	int t; // 이동 횟수
	pos k, r; // 킹의 위치, 돌의 위치
	

	//입력
	cin >> king >> rock >> t;
	k.first = king[0] - 'A';
	k.second = (king[1] - '1');
	r.first = rock[0] - 'A';
	r.second = (rock[1] - '1');

	//연산
	for (int i = 0; i < t; i++) {
		cin >> m;
		move(m, k, r);
	}

	//출력
	king = k.first + 'A';
	king += k.second + '1';
	rock = r.first + 'A';
	rock += r.second + '1';
	cout << king << "\n" << rock;
}