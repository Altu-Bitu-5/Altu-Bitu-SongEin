#include <iostream>
#include <vector>

using namespace std;

int makeTree(vector<vector<int>> &tree, vector<int> &tree_count, int current, int parent) {
	int size = 1;
	for (int i = 0; i < tree[current].size();i++) {
		if (tree[current][i] == parent) {
			continue;
		}
		else {
			size += makeTree(tree, tree_count, tree[current][i], current);
		}
	}
	tree_count[current] = size;
	return size;
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, r, q, temp;
	int begin, end;

	//입력
	cin >> n >> r >> q;
	vector<vector<int>> tree(n+1, vector<int>());
	vector<int> tree_count(n+1);

	for (int i = 0; i < n - 1; i++) {
		cin >> begin >> end;
		tree[begin].push_back(end);
		tree[end].push_back(begin); // 연결관계에 따라 vector에 push
	}

	//연산 및 출력
	makeTree(tree, tree_count, r, -1);

	for (int i = 0; i < q; i++) {
		cin >> temp;
		cout << tree_count[temp] << "\n";
	}
}