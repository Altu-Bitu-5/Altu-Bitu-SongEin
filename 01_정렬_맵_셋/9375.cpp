#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


int main() {
	int t, n, count = 1;
	string c1, c2;
	cin >> t;
	vector<int> v;

	for (int i = 0; i < t; i++) {
		cin >> n;
		unordered_map<string, int> cloth;

		if (n == 0) {
			v.push_back(0);
			continue;
		}
		for (int j = 0; j < n; j++) {
			cin >> c1 >> c2;
			if (cloth.find(c2) == cloth.end()) {
				cloth[c2] = 1;
			}
			else {
				cloth[c2] = cloth[c2] +1;
			}
		}
		for (auto iter = cloth.begin(); iter != cloth.end(); iter++) {
			count = (count * (iter->second + 1));
		}
		v.push_back(count-1);
		count = 1;
	}
	for (int i = 0; i < t; i++) {
		cout << v[i] << endl;
	}
}