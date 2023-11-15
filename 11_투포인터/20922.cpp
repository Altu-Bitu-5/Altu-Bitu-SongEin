#include <iostream>
#include <vector>

using namespace std;

int const  N_max = 200000;
int a_visit[N_max];

int slide(vector<int> &a, int *a_visit, int k, int n) {
	int count = 0;
	int index = 0;
	int ans = 0;

	for (int i = 0; i < n; i++) {
		a_visit[a[i]]++;
		count++;
		while (a_visit[a[i]]> k) { //추가해야하는 슬라이더 번호의 중복 개수가 k개보다 많을 경우
			a_visit[a[index]]--;
			index++; // 슬라이더 앞 인덱스 증가
			count--; // 개수 감소
		}
		ans = max(ans, count);
	}

	return ans;
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, k;

	//입력
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	//연산 및 출력
	cout << slide(a, a_visit, k, n);
}