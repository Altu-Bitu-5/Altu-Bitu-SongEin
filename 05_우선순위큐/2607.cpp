#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

void wordCompare(string w, string ww, int& count, priority_queue<char> pq_st) {

	priority_queue<char> pq_temp;
	int temp = 0, comp = 0;

	if (ww.length() == w.length()) { // 비교 단어와 기준 단어의 길이가 같을 경우
		comp = w.length() - 1; // 기준 단어의 문자 개수 -1 개 이상 일치해야 함
	}
	else if ((ww.length() - w.length()) == 1) { // 비교 단어가 기준 단어보다 길 경우 
		comp = w.length(); // 기준 단어의 문자 개수와 일치해야 함
	}
	else if ((ww.length() - w.length()) == -1) { // 비교 단어가 기준 단어보다 짧을 경우
		comp = ww.length(); // 비교 단어의 문자가 모두 기준 단어와 일치해야 함
	}

	for (int i = 0; i < ww.length(); i++) {
		pq_temp.push(ww[i]);
	}

	while (!pq_st.empty() && !pq_temp.empty()) { //
		if (pq_st.top() == pq_temp.top()) {
			temp++;
			pq_st.pop();
			pq_temp.pop();
		}
		else if (pq_st.top() > pq_temp.top()) {
			pq_st.pop();
		}
		else if (pq_st.top() < pq_temp.top()) {
			pq_temp.pop();
		}
	}

	if (temp >= comp) { // 일치하는 단어 개수와 기준 길이 차이를 비교하여 기준치 이상일 경우
		count++;
	}
}

int main() {
	// 선언
	int n, count = 0;
	string w, ww;
	priority_queue<char> pq_st;

	// 입력
	cin >> n;
	cin >> w;

	// 연산
	for (int i = 0; i < w.length(); i++) {
		pq_st.push(w[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> ww;
		if (abs((int)(w.length() - ww.length())) > 1) { // 길이가 2 이상 차이날 경우 비교 없이 다음 단어로
			continue;
		}
		wordCompare(w, ww, count, pq_st);
	}

	// 출력
	cout << count;	
}