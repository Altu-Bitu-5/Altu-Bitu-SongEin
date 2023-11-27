#include <iostream>
#include <vector>

using namespace std;

const int DXY[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} }; // 시계방향
const int SIZE = 101;

int frame[SIZE][SIZE];

//드래곤 커브를 그리는 함수
void dragon(int x, int y, int d, int g) {
	int dx = x, dy = y, dir = d;
	vector<int> prev_dir;

	//0세대
	frame[dy][dx] = true;
	dx = x + DXY[dir][1];
	dy = y + DXY[dir][0];
	prev_dir.push_back(dir);
	frame[dy][dx] = true;


	for (int i = 1; i <= g; i++) { // 1세대부터
		for (int j = prev_dir.size() -1; j >= 0; j--) {
			dir = (prev_dir[j] + 1) % 4;
			dx += DXY[dir][1];
			dy += DXY[dir][0];
			frame[dy][dx] = true;
			prev_dir.push_back(dir);
		}
	}
}

int square() {
	int ans = 0;

	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - 1; j++) {
			if (frame[i][j] == true && frame[i][j + 1] == true && frame[i + 1][j + 1] == true && frame[i + 1][j] == true) { // 시작점
				ans++;
			}
		}
	}

	return ans;
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n;
	int x, y, d, g;

	//입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;
		dragon(x, y, d, g);
	}

	//연산 및 출력
	cout << square();
}