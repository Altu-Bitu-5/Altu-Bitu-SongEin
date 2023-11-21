#include <iostream>

using namespace std;

int tree[10005];

void traceBack(int start, int end) {
	int index;

	if (start >= end) { // 시작이 끝보다 크거나 같으면 리턴
		return;
	}
	for (index = start + 1; index < end; index++) {
		if (tree[index] > tree[start]) { // 오른쪽 트리의 시작 인덱스를 찾음
			break;
		}
	}
	traceBack(start + 1, index); //재귀적으로 호출. 왼쪽 자식 트리부터 출력
	traceBack(index, end); // 오른쪽 자식 트리
	cout << tree[start] << "\n"; // 부모 노드
}


int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// 선언
	int n, i = 0;

	// 입력
	while(cin >> n) {
		tree[i] = n;
		i++;
	}

	// 연산 및 출력
	traceBack(0, i);
}