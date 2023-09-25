#include <iostream>
#include <queue>

using namespace std;

void queueComp(priority_queue<int, vector<int>, less<int>>& pq_left, priority_queue<int, vector<int>, greater<int>>& pq_right, int n) {
	int temp, count = 0;

	//첫 입력
	cin >> temp;
	pq_left.push(temp);
	count++;
	cout << pq_left.top() << "\n";

	for (int i = 0; i < n - 1; i++) {
		cin >> temp;
		count++;
		if (count % 2 == 1) { //홀수 번째 입력 (왼쪽 큐에 삽입해야 함)
			if (pq_right.top() <= temp) { //오른쪽 큐의 최솟값보다 입력 값이 크면
				pq_left.push(pq_right.top()); // 오른쪽 큐의 최솟값을 왼쪽 큐로 옮기고 temp를 오른쪽 큐에 push
				pq_right.pop();
				pq_right.push(temp);
			}
			else {
				pq_left.push(temp);
			}
		}
		else if (count % 2 == 0) { // 짝수 번째 입력 (오른쪽 큐에 삽입해야 함)
			if (pq_left.top() >= temp) { //왼쪽 큐의 최댓값보다 입력 값이 작으면
				pq_right.push(pq_left.top()); //왼쪽 큐의 최댓값을 오른쪽 큐로 옮기고 temp를 왼쪽 큐에 push
				pq_left.pop();
				pq_left.push(temp);
			}
			else {
				pq_right.push(temp);
			}
		}
		cout << pq_left.top() << "\n";
	}
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n;
	priority_queue<int, vector<int>, less<int>> pq_left; // left queue는 중간값보다 작은 값, 
	priority_queue<int, vector<int>, greater<int>> pq_right; // right queue는 중간값보다 큰 값

	//입력
	cin >> n;

	//연산
	queueComp(pq_left, pq_right, n);
}