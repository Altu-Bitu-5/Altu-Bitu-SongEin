#include <iostream>
#include <array>
const int WORDS = 26; // 알파벳 26자

using namespace std;

string palin(string name) {
	int Alphabet[WORDS] = {0,}; // 알파벳 배열을 선언하고 0으로 초기화
	int odd = -1; // 홀수번 나온 문자가 있는지 판단
	string palin_name = "";


	for (int i = 0; i < name.length(); i++) {
		Alphabet[(name[i] - 'A')]++; // 이름에 들어간 문자의 개수를 카운트
	}

	for (int i = 0; i < WORDS; i++) {
		if (Alphabet[i] == 0) { // 문자가 포함되지 않을 경우
			continue; // 다음 문자로
		}
		else if (Alphabet[i] % 2 == 0) { // 문자가 짝수 개 있을 경우
			for (int j = 0; j < Alphabet[i] / 2; j++) { // 개수의 절반 만큼 palin_name에 넣음
				palin_name += i + 'A';
			}
		}
		else if (Alphabet[i] % 2 == 1) {
			if (odd > -1) { // 홀수 개 있는 문자가 2개 이상일 경우
				return "I'm Sorry Hansoo"; // 팰린드롬을 만들 수 없음
			}
			else {
				odd = i;
				for (int j = 0; j < Alphabet[i] / 2; j++) { // 개수의 절반 만큼 palin_name에 넣음
					palin_name += i + 'A';
				}
			}
		}
	}
	if (odd > -1) {
		palin_name += odd + 'A'; //홀수 개 있는 문자를 가운데에 넣음
	}
	for (int i = WORDS - 1; i >= 0; i--) { //반전하여 계산
		if (Alphabet[i] == 0) { // 문자가 포함되지 않을 경우
			continue; // 다음 문자로
		}
		else if (Alphabet[i] > 0) { // 문자가 포함될 경우
			for (int j = 0; j < Alphabet[i] / 2; j++) { // 개수의 절반 만큼 palin_name에 넣음
				palin_name += i + 'A';
			}
		}
	}
	return palin_name;
}

int main() {
	//선언 
	string name, palin_name;

	//입력
	cin >> name;

	//연산
	palin_name = palin(name);

	//출력
	cout << palin_name;
}