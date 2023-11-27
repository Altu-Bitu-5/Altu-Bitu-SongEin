#include <iostream>

using namespace std;

const int N = 501;

bool height[N][N];

void floyd(int n) {
	for (int k = 1; k <= n; k++) { // 중간 정점
		for (int i = 1; i <= n; i++) { // 출발 정점
			for (int j = 1; j <= n; j++) { // 도착 정점
				if (height[i][k] && height[k][j]) { // 키에 대한 정보가 있으면
					height[i][j] = true; // 알 수 있다고 표시
				}
			}
		}
	}
}

int count(int n) {
	int count, ans = 0;

	for (int i = 1; i <= n; i++) {
		count = 0;
		for (int j = 1; j <= n; j++) {
			if (height[i][j] || height[j][i]) {
				count++;
			}
		}
		if (count == n - 1) {
			ans++;
		}
	}

	return ans;
}


int main() {
	//선언
	int n, m;
	int a, b;

	//입력
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		height[a][b] = true;
	}

	//연산
	floyd(n);

	//출력
	cout << count(n);
}