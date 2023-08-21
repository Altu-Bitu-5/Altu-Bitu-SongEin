#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b) {
	if (a.length() != b.length()) {
		return (a.length() < b.length());
	}
	int a_num = 0, b_num = 0;
	for (int i = 0; i < a.length(); i++) {
		if(a[i] > 47 && a[i] < 58){
			a_num = a_num + (a[i] - 48);		
		}
	}
	for (int i = 0; i < b.length(); i++) {
		if (b[i] > 47 && b[i] < 58) {
			b_num = b_num + (b[i] - 48);
		}
	}
	if (a_num != b_num) {
		return a_num < b_num;
	}
	return a < b;
}

int main() {
	int t;
	cin >> t;
	vector<string> guitar(t);
	for (int i = 0; i < t; i++) {
		cin >> guitar[i];
	}

	sort(guitar.begin(), guitar.end(), cmp);

	for (int i = 0; i < t; i++) {
		cout << guitar[i] << endl;
	}
}