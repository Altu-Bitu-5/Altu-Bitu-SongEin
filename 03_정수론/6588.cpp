#include <iostream>
#include <vector>
#include <cmath>
#define N 1000001 //N은 최대 1000000


using namespace std;


//에라토스테네스의 체, 홀수만 대상으로
void eratos(vector<bool>& v) {
	v[1] = false;
	for (int i = 3; i <= sqrt(N); i += 2) {
		if (!v[i]) {
			continue;
		}
		for (int j = (i*3); j < N; j += i) {
			v[j] = false;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num = 1, i;
	vector<bool> v(N, true);
	eratos(v);
	
	while (true) {
		//입력
		cin >> num;
		if (num == 0) {
			break;
		}
		for (i = num - 1; i >= num / 2; i -= 2) { //마찬가지로 홀수 대상으로 뒤에서부터 확인
			if (v[i] && v[num - i]) {
				cout << num << " = " << (num - i) << " + " << i << "\n";
				break;
			}
		}
		if (i < num / 2) {
			cout << "Goldbach's conjecture is wrong.";
		}
	}
}