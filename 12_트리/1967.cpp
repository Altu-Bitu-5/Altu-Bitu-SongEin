#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];

void diameter(int point, int dist, int &ans, int &node) {
	visited[point] = true;

	if (dist > ans) {
		ans = dist;
		node = point;
	}

	for (int i = 0; i < tree[point].size(); i++) {
		if (!visited[tree[point][i].first]) {
			diameter(tree[point][i].first, dist + tree[point][i].second, ans, node);
		}
	}
}

int main() {
	// 선언
	int n;
	int p, c, l;
	int ans = 0, node = 1;

	// 입력
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> p >> c >> l;
		tree[p].push_back({ c,l });
		tree[c].push_back({ p, l });
	}
	
	// 연산
	diameter(1, 0, ans, node); //1부터 가장 먼 노드를 구한 다음
	
	for (int i = 0; i < n + 1; i++) {
		visited[i] = false; //초기화
	}
	diameter(node, 0, ans, node); //노드로부터 가장 먼 노드를 다시 구함
	

	// 출력
	cout << ans;

}