#include <iostream>
#include <vector>
#include <algorithm>
const int DXY[4][2] = { {1,0}, {-1, 0},{0, 1}, {0, -1} }; //동,서,남, 북

using namespace std;

//전역변수 선언
int ans, n, m;

void dfs(vector<vector<int>>& board, vector<vector<bool>>& board_bool, int count, int sum, int i, int j) { // ㅏ, ㅓ, ㅗ, ㅜ 모양을 제외한 나머지 문양을 dfs로 탐색

	if (count == 4) { // 반환 조건
		ans = max(ans, sum);
		return;
	}
	if ((i < 0 || j < 0) || (i >= n || j >= m)) { //좌표값이 범위를 초과하는 경우 중단
		return;
	}
	if (board_bool[i][j] == true) { // 이미 지나온 좌표일 경우에도 중단
		return;
	}
	else {
		board_bool[i][j] = true;
	}

	for (int k = 0; k < 4; k++) {
		dfs(board, board_bool, count + 1, sum + board[i][j], i + DXY[k][0], j + DXY[k][1]);
	}
	board_bool[i][j] = false;
}

void tetrominoExceptV(vector<vector<int>>& board, int i, int j) { // ㅏ,ㅓ 모양에 대한 탐색
	int sum = 0;
	
	if (i > n - 3) {
		return;
	}

	// ㅏ, ㅓ
	for (int k = 0; k < 3; k++) {
		sum += board[i + k][j];
	}
	if (j < m - 1) { // ㅏ
		ans = max(ans, sum + board[i + 1][j + 1]);
	}
	if (j > 0) { // ㅓ
		ans = max(ans, sum + board[i + 1][j - 1]);
	}
}

void tetrominoExceptH(vector<vector<int>>& board, int i, int j) { // ㅗ,ㅜ 모양에 대한 탐색
	int sum = 0;

	if (j > m - 3) {
		return;
	}

	// ㅗ, ㅜ
	for (int k = 0; k < 3; k++) {
		sum += board[i][j + k];
	}
	if (i > 0) { // ㅗ
		ans = max(ans, sum + board[i - 1][j + 1]);
	}
	if (i < n - 1) { // ㅜ
		ans = max(ans, sum + board[i + 1][j + 1]);
	}
}

int main() {

	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//입력
	cin >> n >> m;
	vector<vector<int>> board(n, vector<int>(m));
	vector<vector<bool>> board_bool(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	//연산
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dfs(board, board_bool, 0, 0, i, j);
			tetrominoExceptV(board, i, j);
			tetrominoExceptH(board, i, j);
		}
	}

	//출력
	cout << ans;
}