# include <iostream>
# include <vector>
# include <queue>
# define MAXS 1e6

using namespace std;
typedef pair<int, int> pi;



vector<int> dijkstra(int v, int start, vector<vector<pi>> nodes) {
    vector<int> dist(v+1, MAXS);
    priority_queue<pi, vector<pi>, greater<>> pq; // 거리, 정점
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        for (int i=0; i<nodes[vertex].size(); i++) {
            int nCost = cost + nodes[vertex][i].second;
            int nVertex = nodes[vertex][i].first;
            if (dist[nVertex] > nCost) {
                dist[nVertex] = nCost;
                pq.push({nCost, nVertex});
            }
        }
    }

    return dist;
}

int main() {
    int vertex, e;
    cin >> vertex >> e;
    int start;
    cin >> start;
    vector<vector<pi>> nodes(vertex+1);
    for (int i=0; i<e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        nodes[u].push_back({v,w});
    }

    vector<int> dist = dijkstra(vertex, start, nodes);

    for (int i=1; i<=vertex; i++) {
        if (dist[i] == MAXS) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}