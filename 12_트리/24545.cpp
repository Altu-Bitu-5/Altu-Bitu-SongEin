#include <iostream>
#include <vector>
const int MAX = 100001;

using namespace std;

vector<int> tree[MAX];
bool visited[MAX];

void diameter(int point, int prev, int dist, int& cur_dist, int& node) {

	if (dist > cur_dist) {
		cur_dist = dist;
		node = point;
	}

	for (int i = 0; i < tree[point].size(); i++) {
		if (tree[point][i] == prev) {
			continue;
		}
		diameter(tree[point][i], point, dist + 1, cur_dist, node);
	}
}

bool routeTrace(int point, int node_end, int prev, int dist, vector<int>& route) {

	if (point == node_end) {
		route[dist] = point;
		return true;
	}
	for (int i = 0; i < tree[point].size(); i++) {
		if (tree[point][i] == prev) {
			continue;
		}
		if (routeTrace(tree[point][i], node_end, point, dist + 1, route)) {
			route[dist] = point;
			return true;
		}
	}
	return false;
}

void branchSearch(int point, int dist, int &side_len) {
	visited[point] = true;

	for (int i = 0; i < tree[point].size(); i++) {
		if (!visited[tree[point][i]]) {
			branchSearch(tree[point][i], dist + 1, side_len);
		}
	}

	side_len = max(side_len, dist);
}

int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//선언
	int n, u, v;
	int i;
	int diameter_len = -1, side_len = 1; // 지름 길이와 지름에서 뻗어나오는 길의 길이
	int node_start = 0, node_end = 0; // 지름의 시작 노드와 끝 노드
	vector<int> route(MAX);

	//입력
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	//연산
	if (n < 4) { // Y트리를 만들 수 없는 경우 1: Y-트리를 만족하기 위해서는 최소한 정점이 4개 이상 필요
		cout << 0;
		return 0;
	}

	// 1단계: 지름과 양끝값 노드를 구함
	diameter(1, 0, 0, diameter_len, node_start); //1부터 가장 먼 노드
	diameter_len = -1;
	diameter(node_start, 0, 0, diameter_len, node_end); //노드로부터 가장 먼 노드

	//2단계: 지름 경로를 구함
	routeTrace(node_start, node_end, 0, 0, route); // 첫 번째 노드부터 두 번째 노드 (지름) 까지의 루트를 구함

	//3단계: 지름 경로상에서 가장 깊게 뻗어나가는 가지를 찾음
	for (i = 0; i <= diameter_len; i++) {
		visited[route[i]] = true;
	}
	
	for (i = 1; i < diameter_len; i++) {
		branchSearch(route[i], 1, side_len);
	}

	if (side_len < 2) { // Y트리를 만들 수 없는 경우 2: Y트리를 만들기 위해서는 지름까지의 루트에서 뻗어나오는 최소 길이가 2이상이어야 함.
		cout << 0;
		return 0;
	}

	//출력
	cout << side_len + diameter_len;	
}