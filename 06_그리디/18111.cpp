#include <iostream>
const int MAXTIME = 1280000000; //최대 시간. 500*500*256*2
const int MAXHEIGHT = 256;

using namespace std;

void mine(int house[500][500], int n, int m, int b) {
	int count, use_block, mine_block, time = MAXTIME, height = 0;

	for (int h = 0; h <= MAXHEIGHT; h++) { //브루트포스
		use_block = 0;
		mine_block = 0;	//초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (house[i][j] > h) { // 목표 높이보다 터 높이가 높으면
					mine_block += house[i][j] - h;
				}
				else { // 목표 높이보다 터 높이가 낮으면
					use_block += h - house[i][j];
				}
			}
		}
		if (use_block > mine_block + b) { // 블록 개수 부족으로 성립 불가능인 경우
			continue; // 다음 경우로
		}
		count = use_block + (mine_block * 2); //시간 계산
		if (time >= count) { //같을 경우에도 갱신하여 가장 높도록
			time = count;
			height = h;
		}
	}
	cout << time << " " << height;
}


int main() {
	//선언
	int n, m, b;
	int house[500][500]; // n,m은 최대 500이므로 미리 선언

	//입력
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> house[i][j];
		}
	}

	//연산 및 출력
	mine(house, n, m, b);
}