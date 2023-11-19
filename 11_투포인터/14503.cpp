#include <iostream>

using namespace std;

int room[50][50];
int room_visit[50][50];

int robot(int r, int c, int d) {
	int count = 0;
	bool back;
	int r_now = r, c_now = c;
	int dir[4][2] = { {-1, 0},{0,-1},{1,0},{0,1} }; // 북, 서, 남, 동 반시계 회전
	int robot_dir;

	//초기 위치 설정
	if (d % 2 == 1) {
		robot_dir = (d + 2) %4;
	}
	else {
		robot_dir = d;
	}
	
	while (true) {
		if (room[r_now][c_now] == 0) { // 청소하지 않은 방에 도달시
			count++;
			room[r_now][c_now] = 2; //청소된 상태를 2로 가정
		}
		back = true;
		for (int i = 1; i < 5; i++) {
			if (room[r_now + dir[(robot_dir + i) % 4][0]][c_now + dir[(robot_dir + i) % 4][1]] == 0) { // 주변 4칸에 청소하지 않은 칸이 있을 경우
				robot_dir = (robot_dir + i) % 4;
				r_now += dir[robot_dir][0];
				c_now += dir[robot_dir][1];
				back = false;
				break;
			}
		}
		if (back && room[r_now - dir[robot_dir][0]][c_now - dir[robot_dir][1]] != 1) { //후진해야 하고 후진할 수 있을 때
			r_now -= dir[robot_dir][0];
			c_now -= dir[robot_dir][1];
		}
		else if (back) { //후진할 수 없는데 후진해야 할 때
			return count; // 수치를 리턴하고 종료
		}
	}
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, m;
	int r, c, d;

	//입력
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
		}
	}

	//출력
	cout << robot(r, c, d);
}