#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> graph;
bool visited[1002];
void dfs(int cur) {
	visited[cur] = 1;
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (!visited[next]) 
			dfs(next);
	}
}


int main() {

	cin >> n >> m;

	graph.assign(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;
		dfs(i);
		cnt++;
	}
	cout << cnt;

	return 0;
}