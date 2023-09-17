#include <iostream>

using namespace std;

int getGcdRec(int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcdRec(b, a%b);
}

int main() {
	//입력
	int a_nu, a_de, b_nu, b_de, lcm, ab_gcd, dn_gcd, num;
	cin >> a_nu >> a_de;
	cin >> b_nu >> b_de;

	//통분
	ab_gcd = getGcdRec(a_de, b_de);
	lcm = a_de * b_de / ab_gcd;
	a_nu = a_nu * (lcm / a_de);
	b_nu = b_nu * (lcm / b_de);
	num = a_nu + b_nu;

	//약분
	dn_gcd = getGcdRec(lcm, num);
	num = num / dn_gcd;
	lcm = lcm / dn_gcd;

	//출력
	cout << num << " " << lcm;
}