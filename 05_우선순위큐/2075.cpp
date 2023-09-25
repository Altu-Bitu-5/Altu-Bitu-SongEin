#include <iostream>
#include <queue>

using namespace std;

void nthNum(int n, priority_queue<int, vector<int>, greater<int>>& pq) {
	int temp;
	for (int i = 0; i < n*n; i++) {
		cin >> temp;
		pq.push(temp);
		if (pq.size() > n) {
			pq.pop();
		}
	}	
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n;
	priority_queue<int, vector<int>, greater<int>> pq;

	//입력
	cin >> n;

	//연산
	nthNum(n, pq);

	//출력
	cout << pq.top();
}