#include <iostream>
#include <vector>

using namespace std;

void con(int broken, int &ans, int n, int k, int step, int index, vector<int> &a, vector<bool> &b) {
	//1. 벨트의 회전 -> 올리는 위치 인덱스 계산
	index = ((n * 2) + index - 1) % (n * 2);

	//내리는 위치 인덱스 계산
	int temp = ((n * 2) + index + (n - 1)) % (n * 2);

	// 내리는 위치에 도달한 로봇은 내린다.
	b[temp] = false;

	int from, to;
	//2. 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
	for (int i = 1; i < n; i++) {
		from = (n * 2 + temp - i) % (n * 2);
		to = (n * 2 + temp - i + 1) % (n * 2);
		if ((b[from] == true && b[to] == false)&& a[to] > 0) {
			b[from] = false;
			b[to] = true;
			a[to]--; //내구도 감소
			if (a[to] == 0) { //내구도가 떨어져 0이 되면
				broken++; //내구도가 0인 칸의 개수 증가
			}
		}
	}
	// 내리는 위치에 도달한 로봇은 내린다.
	b[temp] = false;

	//3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇을 올린다.
	if (a[index] > 0) {
		b[index] = true;
		a[index]--;
		if (a[index] == 0) { //내구도가 떨어져 0이 되면
			broken++; //내구도가 0인 칸의 개수 증가
		}
	}

	//4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다.그렇지 않다면 1번으로 돌아간다.	
	if (broken >= k) { //종료 조건
		ans = step;
		return;
	}
	con(broken, ans, n, k, step + 1, index, a, b);
}

int main() {
	//선언
	int n, k, ans = 1;
	int index = 0; // 1번 칸의 위치

	//입력
	cin >> n >> k;
	vector<int> a(2 * n);
	vector<bool> b(2 * n, false);

	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i];
	}
	
	//연산
	con(0, ans, n, k, 1, index, a, b);

	//출력
	cout << ans;
}