#include <iostream>
#include <vector>
const int DXY[8][8] = { {-1,0},{-1,1},{-1,-1},{0,1},{0,-1},{1,0 }, {1,1}, {1,-1} }; //8방향

using namespace std;

void dfs(vector<vector<int>>& v, vector<vector<bool>>& visit, int h, int w, int i, int j) {
	visit[i][j] = true;
	int x, y;

	for (int k = 0; k < 8; k++) {
		x = i + DXY[k][0];
		y = j + DXY[k][1];

		if ((x >= 0 && x < h) && (y >= 0 && y < w)) {
			if (v[x][y] == 1 &&  !visit[x][y]) { //섬이면서 방문하지 않았을 때
				dfs(v, visit, h, w, x, y);
			}
		}
	}

}

int main() {
	//선언
	int w, h, ans = 0;

	//입력, 연산 및 출력
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		vector<vector<int>> v(h, vector<int>(w));
		vector<vector<bool>> visit(h, vector<bool>(w, false));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> v[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				// 땅이고(1) 방문하지 않았을 때
				if (v[i][j] == 1 && !visit[i][j]) {
					ans++;
					dfs(v, visit, h, w, i, j);
				}
			}
		}
		cout << ans << "\n";
		ans = 0;
	}
}