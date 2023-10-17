#include <iostream>

using namespace std;

const int SIZE = 19;

void omock(int board[SIZE][SIZE], int ans[]) {
	int dir[4][2] = { { 0,1 }, { 1,0 }, { -1, 1 }, { 1,1 } }; //가로, 세로, 오른쪽 아래 대각선, 오른쪽 위 대각선
	int count, pl;
	int x, y;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (board[i][j] == 0) { // 돌이 없으면 continue
				continue;
			}
			// 돌이 있을 경우
			pl = board[i][j];
			for (int k = 0; k < 4; k++) {
				// 역방향에 돌이 놓여있었을 경우 (이미 체크한 경우) 확인
				x = i - dir[k][0];
				y = j - dir[k][1];
				if (((x >= 0 && x < 19) && (y >= 0 && y < 19)) && board[x][y] == pl) {
					continue; //건너뜀
				}
				//역방향에 돌이 없을 경우
				x = i;
				y = j;
				count = 1;
				while (true) {
					x += dir[k][0];
					y += dir[k][1];
					if (((x >= 0 && x < 19) && (y >= 0 && y < 19))&& board[x][y] == pl) { // 방향으로 전진하는 동안 같은 말이 반복될 경우
						count++;
					}
					else {
						break;
					}
				}
				if (count == 5) { // count가 5일 경우
					ans[0] = pl;
					ans[1] = i + 1;
					ans[2] = j + 1;
					return;
				}
			}
		}
	}
	ans[0] = 0;
}


int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int board[SIZE][SIZE];
	int ans[3];

	//입력
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cin >> board[i][j];
		}
	}

	//연산
	omock(board, ans);

	//출력
	cout << ans[0];
	if (ans[0] > 0) {
		cout << "\n" << ans[1] << " " << ans[2];
	}
}