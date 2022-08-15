#include<iostream>
#include<queue>
#include<vector>

using namespace std;
const int INF = 1e6;
typedef pair<int, int> ci;

vector<int> dijkstra(int v, vector<vector<ci>> &graph, int k) {
	vector<int> dist(v + 1, INF);
	priority_queue<ci, vector<ci>, greater<>> pq; //first 시작 점으로부터의 거리, second 정점

	dist[k] = 0;
	pq.push(make_pair(0, k));
	
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		if (cost > dist[vertex])
			continue;
		for (int i = 0; i < graph[vertex].size(); i++) {
			int nextCost = cost + graph[vertex][i].second; // 시작점으로부터의 거리
			int nextVertex = graph[vertex][i].first; // 연결된 정점

			if (dist[nextVertex] > nextCost) {
				dist[nextVertex] = nextCost;
				pq.push(make_pair(nextCost, nextVertex));
			}
	
		}
	}

	return dist;
}

int main() {
	int v, e, k;
	cin >> v >> e;
	cin >> k;
	vector<vector<ci>> graph(v + 1, vector<ci>(0));

	while (e--) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].emplace_back(v, w);
	}

	vector<int> result = dijkstra(v, graph, k);


	for (int i = 1; i <= v; i++) {
		if (result[i] == INF)
			cout << "INF" << '\n';
		else
			cout << result[i] << '\n';
	}

	return 0;
}