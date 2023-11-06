#include <iostream>
#include <vector>

using namespace std;

void con(int broken, int& ans, int n, int k, int step, int index, vector<int>& belt, vector<bool>& belt_bool) {
	//1. 벨트의 회전 -> 올리는 위치 인덱스 계산
	int index_up = ((n * 2) + index - 1) % (n * 2);

	//내리는 위치 인덱스 계산
	int index_down = ((n * 2) + index_up + (n - 1)) % (n * 2);

	// 내리는 위치에 도달한 로봇은 내린다.
	belt_bool[index_down] = false;

	int from, to;
	//2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
	for (int i = 1; i < n; i++) {
		from = (n * 2 + index_down - i) % (n * 2);
		to = (n * 2 + index_down - i + 1) % (n * 2);
		if ((belt_bool[from] == true && belt_bool[to] == false) && belt[to] > 0) {
			belt_bool[from] = false;
			belt_bool[to] = true;
			belt[to]--; //내구도 감소
			if (belt[to] == 0) { //내구도가 떨어져 0이 되면
				broken++; //내구도가 0인 칸의 개수 증가
			}
		}
	}
	// 내리는 위치에 도달한 로봇은 내린다.
	belt_bool[index_down] = false;

	//3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
	if (belt[index_up] > 0) {
		belt_bool[index_up] = true;
		belt[index_up]--;
		if (belt[index_up] == 0) { //내구도가 떨어져 0이 되면
			broken++; //내구도가 0인 칸의 개수 증가
		}
	}

	//4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.그렇지 않다면 1번으로 돌아간다.	
	if (broken >= k) { //종료 조건
		ans = step;
		return;
	}
	con(broken, ans, n, k, step + 1, index_up, belt, belt_bool);
}

int main() {
	//선언
	int n, k, ans = 1;
	int index = 0; // 1번 칸의 위치

	//입력
	cin >> n >> k;
	vector<int> belt(2 * n);
	vector<bool> belt_bool(2 * n, false);

	for (int i = 0; i < 2 * n; i++) {
		cin >> belt[i];
	}

	//연산
	con(0, ans, n, k, 1, index, belt, belt_bool);

	//출력
	cout << ans;
}