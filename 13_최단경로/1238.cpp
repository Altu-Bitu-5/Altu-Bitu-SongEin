#include <iostream>
#include <vector>
#include <queue>
#define pint pair<int, int> // first: 걸리는 시간, second: 정점 number

using namespace std;

const int INF = 1e9+7;

void dijkstra(int index, int num, vector<vector<pint>> &graph, vector<vector<int>> &dist) {

	priority_queue<pint, vector<pint>, greater<pint>> pq;

	dist[index][index] = 0;
	pq.push({0, index });

	while (!pq.empty()) {
		int weight = pq.top().first; // 현재 정점까지의 경로값
		int node = pq.top().second; // 현재 탐색하는 정점

		pq.pop();

		if (weight > dist[index][node]) {
			continue;
		}
		for (int i = 0; i < graph[node].size(); i++) {
			int next_node = graph[node][i].second;
			int next_weight = weight + graph[node][i].first;
			if (next_weight < dist[index][next_node]) {
				dist[index][next_node] = next_weight;
				pq.push({ next_weight, next_node });
			}
		}
	}
}


int main() {
	//입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	//선언
	int n, m, x;
	int a, b, t;
	int ans = 0;
	

	//입력
	cin >> n >> m >> x;
	vector<vector<pint>> graph(n + 1, vector<pint>());
	vector<vector<int>> dist(n + 1,vector<int>(n + 1, INF));
	
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> t;
		graph[a].push_back({ t, b });
	}

	//연산
	for (int i = 1; i <= n; i++) {
		dijkstra(i, 0, graph, dist);
	}

	for (int i = 0; i <= n; i++) {
		if (dist[i][x] != INF && dist[x][i] != INF) {
			ans = max(ans, dist[i][x] + dist[x][i]);
		}
	}

	//출력
	cout << ans;
}