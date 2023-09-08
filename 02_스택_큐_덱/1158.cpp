#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//�似Ǫ�� ������ ���ϴ� �Լ�
void Josephus(int n, int k, queue<int> &q, vector<int> &v) {
	int flag = 1;
	while (!q.empty()) {
		if (flag == k) { // k��° ������ ��� ���� ��¿� ���Ϳ� ����
			v.push_back(q.front());
			q.pop();
			flag = 1; // flag �ʱ�ȭ
		}
		else { // k��° ���ڰ� �ƴ� ��� queue�� �ڿ� push�ϰ� pop
			q.push(q.front());
			q.pop();
			flag++;
		}
	}
}

int main() {

	int n, k;
	queue<int> q;

	//�Է�
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	//�Լ� ����
	Josephus(n, k, q, v);

	//���
	cout << "<" << v[0];
	for (int i = 1; i < v.size(); i++) {
		cout << ", " << v[i];
	}
	cout << ">";
}