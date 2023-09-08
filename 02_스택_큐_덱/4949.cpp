#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool stackIn(stack<char>& s, string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '[' || str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ']') {
			if (s.empty()) {
				return false;
			}
			else if (s.top() == '[') {
				s.pop();
			}
			else {
				return false;
			}
		}
		else if (str.substr(i, 1) == ")") {
			if (s.empty()) {
				return false;
			}
			else if (s.top() == '(') {
				s.pop();
			}
			else {
				return false;
			}
		}
	}
	return true;
}

int main() {

	string str;
	stack<char> s;

	while (true) {
		//입력
		getline(cin, str, '.');
		cin.ignore();
				
		if (str == "") {
			break;
		}

		//출력
		if (stackIn(s, str) && s.empty()) {
			cout << "yes" << "\n";
		}
		else {
			cout << "no" << "\n";
		}

		//스택 초기화
		while (!s.empty()) {
			s.pop();
		}
	}
}