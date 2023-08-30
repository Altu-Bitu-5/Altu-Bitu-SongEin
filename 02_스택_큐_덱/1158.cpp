#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//요세푸스 순열을 구하는 함수
void Josephus(int n, int k, queue<int> &q, vector<int> &v) {
	int flag = 1;
	while (!q.empty()) {
		if (flag == k) { // k번째 숫자일 경우 정답 출력용 벡터에 저장
			v.push_back(q.front());
			q.pop();
			flag = 1; // flag 초기화
		}
		else { // k번째 숫자가 아닐 경우 queue의 뒤에 push하고 pop
			q.push(q.front());
			q.pop();
			flag++;
		}
	}
}

int main() {

	int n, k;
	queue<int> q;

	//입력
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	//함수 연산
	Josephus(n, k, q, v);

	//출력
	cout << "<" << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << ", " << v[i];
	}
	cout << ">";
}