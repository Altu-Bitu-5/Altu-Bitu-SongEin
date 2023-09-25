#include <iostream>
#include <queue>

using namespace std;

void santa(int n) {
	priority_queue<int> pq;
	int a;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a == 0) {
			if (pq.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			for (int j = 0; j < a; j++) {
				int temp;
				cin >> temp;
				pq.push(temp);
			}
		}
	}
}

int main() {
	//선언
	int n;

	//입력
	cin >> n; //거점지 방문 횟수

	//연산 및 출력
	santa(n);
}