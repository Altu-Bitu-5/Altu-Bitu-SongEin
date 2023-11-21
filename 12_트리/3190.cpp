#include <iostream>
#include <vector>
const int DXY[4][2] = { {0, 1},{1, 0},{0, -1},{-1, 0} }; // 동 남 서 북

using namespace std;

int board[101][101];

void snake(int n, int t, int &cur_t, int dir_int, int &dead, int& x_head, int& y_head, int& x_tail, int& y_tail, vector<int> &dir_v) {
	if (dead > 0) { // 이미 앞에서 뱀이 죽었을 경우 함수 종료
		return;
	}
	while (true) {
		cur_t++;
		dir_v.push_back(dir_int); // 이동 기록 추가
		x_head += DXY[dir_int][0];
		y_head += DXY[dir_int][1]; // 좌표 증가
		if ((x_head > n || y_head > n)|| (x_head <= 0 || y_head <= 0)) { // 머리가 벽에 닿는 경우
			dead = cur_t;
			return;
		}
		if (board[x_head][y_head] == 2) { // 머리가 몸에 닿는 경우
			dead = cur_t;
			return;
		}
		else if(board[x_head][y_head] == 1) { //사과에 닿는 경우
			board[x_head][y_head] = 2; // 몸이 차지하는 자리를 표시
		}
		else {
			board[x_tail][y_tail] = 0; // 꼬리를 비움
			x_tail += DXY[dir_v.front()][0];
			y_tail += DXY[dir_v.front()][1]; // 꼬리 좌표 이동
			dir_v.erase(dir_v.begin()); // 이동 기록 삭제
			board[x_head][y_head] = 2; // 몸이 차지하는 자리를 표시
		}
		if (cur_t == t) {
			return;
		}
	}
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, k, l;
	int x, y;
	int x_head = 1, y_head = 1; //뱀 머리 좌표
	int x_tail = 1, y_tail = 1; // 뱀 꼬리 시작 좌표
	int t, cur_t = 0;
	char dir;
	int dir_int = 0;
	vector<int> dir_v;
	int dead = -1; // 게임이 끝나는 시간

	//입력
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		board[x][y] = 1; // 사과가 있는 자리
	}

	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> t >> dir;
		snake(n, t, cur_t, dir_int, dead, x_head, y_head, x_tail, y_tail, dir_v);
		//방향 전환
		if (dir == 'L') {
			dir_int = (dir_int + 4 - 1) % 4;
		}
		else if (dir == 'D') {
			dir_int = (dir_int + 4 + 1) % 4;
		}
	}
	snake(n, -1, cur_t, dir_int, dead, x_head, y_head, x_tail, y_tail, dir_v); // 마지막 방향전환 이후

	//출력
	cout << dead;
}