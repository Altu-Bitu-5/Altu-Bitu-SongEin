#include <iostream>
#include <vector>

using namespace std;

int slide(vector<int> &sushi, vector<int> &sushi_visit, int k, int c, int n) {
	int count = 0;
	int ans = 0;

	for (int i = 0; i < k; i++) {
		if (sushi_visit[sushi[i]] == 0) {
			count++;
		}
		sushi_visit[sushi[i]]++;
	}
	if (sushi_visit[c] == 0) {
		ans = count + 1;
	}
	else {
		ans = count;
	}
	

	for (int i = 0; i < n; i++) {
		//슬라이더 앞쪽
		sushi_visit[sushi[i]]--;
		if (sushi_visit[sushi[i]] == 0) {
			count--;
		}
		//슬라이더 뒤쪽
		if (sushi_visit[sushi[(i + k) % n]] == 0) {
			count++;
		}
		sushi_visit[sushi[(i + k) % n]]++;

		if (sushi_visit[c] == 0) { //쿠폰 확인
			ans = max(count + 1, ans);
		}
		else {
			ans = max(count, ans);
		}
	}

	return ans;
}

int main() {
	//선언
	int n, d, k, c, ans;

	//입력
	cin >> n >> d >> k >> c;
	vector<int> sushi(n); //초밥 접시
	vector<int> sushi_visit(d+1); //초밥 종류

	for (int i = 0; i < n; i++) {
		cin >> sushi[i];
	}

	//연산 및 출력
	cout << slide(sushi, sushi_visit, k, c, n);
}