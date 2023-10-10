#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int dfs(vector<vector<int>> &computer, int &n, int &c) {
	stack<int> s;
	vector<bool> visit(n+1, false); //방문한 컴퓨터 체크
	int count, index, temp;
	bool child = false;

	s.push(c); //c번째 컴퓨터부터 시작
	visit[c] = true;
	count = 0;

	while (!s.empty()) {
		index = s.top(); //stack 제일 위쪽의 index를 저장
		//child = false;
		s.pop(); // 꺼냄
		count++; // 카운트를 올림

		for (int i = 0; i < computer[index].size(); i++) { //index와 연결된 노드들 확인
			temp = computer[index][i];
			if (!visit[temp]) { // 방문한 적이 없을 경우
				s.push(temp); // 스택에 추가
				visit[temp] = true; // 이후 방문을 true로
			}
		}
	}
	return count;
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, m, a, b, max, temp;
	max = 1;
	vector<int> ans;

	//입력
	cin >> n >> m;
	vector<vector<int>> computer(n+1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		computer[b].push_back(a); //b를 기준으로 b를 신뢰하는 a를 벡터에 나열
	}

	//연산
	for (int i = 1; i <= n; i++) {
		temp = dfs(computer, n, i);
		if (max < temp) {
			ans.clear();
			ans.push_back(i);
			max = temp;
		}
		else if (max == temp) {
			ans.push_back(i); //i가 작은 것부터 순서대로 확인하므로 오름차순으로 정렬됨.
		}
	}

	//출력
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}