#include <iostream>
#include <stack>

using namespace std;

void StackIn(string num, stack<int>& st) {
	for(int i = 0; i < num.length(); i++) {
		st.push(num[i]-'0');
	}
}

void StackSum(stack<int>& a, stack<int>& b, stack<int> &sum) {
	int s, r, q = 0;
	int t = a.size();

	for (int i = 0; i < t; i++) {
		if (b.empty()) {
			s = a.top() + q;
			q = s / 10;
			r = s % 10;
			sum.push(r);
			a.pop();
			continue;
		}
		s = a.top() + b.top() + q;
		q = s / 10;
		r = s % 10;
		sum.push(r);
		a.pop();
		b.pop();
	}
	if (q > 0) {
		sum.push(q);
	}
	return;
}

int main() {

	string a, b;
	stack<int> a_stack;
	stack<int> b_stack;
	stack<int> sum;

	//�Է�
	cin >> a >> b;

	//����
	StackIn(a, a_stack);
	StackIn(b, b_stack);
	
	if (a.length() > b.length()) { //�ڸ����� ū ���� ������ ������ �Լ� ȣ��
		StackSum(a_stack, b_stack, sum);
	}
	else {
		StackSum(b_stack, a_stack, sum);
	}

	//���
	int t = sum.size();
	for (int i = 0; i < t; i++) {
		cout << sum.top();
		sum.pop();
	}
}