#include <iostream>
#include <vector>

using namespace std;
int k, V, E; // 정점의 수, 간선 수
vector<int> visited;
vector<vector<int>> graph;

void findBinaryGraph(int node, int num) {


    for (int i = 0; i < graph[node].size(); i++) {
        if (visited[graph[node][i]] == -1) {
            visited[graph[node][i]] = num;
            findBinaryGraph(graph[node][i], (num + 1) % 2);

        }
    }
}

bool check() {


    for (int i = 1; i <graph.size(); i++) { // 여기 graph.size()랑 같을때까지로 함
        for (int j = 0; j < graph[i].size(); j++) {
            if (visited[graph[i][j]] == visited[i]) {
                return false;
            }
        }
    }

    return true;

}

int main() {


    int u, v;
    cin >> k;


    for (int i = 0; i < k; i++) {
        cin >> V >> E;
        graph.assign(V + 1, vector<int>());
        visited.assign(V + 1, -1);

        for (int j = 0; j < E; j++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int j = 1; j <= V; j++) {
            if (visited[j] == -1) {

                visited[j] = 0;
                findBinaryGraph(j, 1);
            }

        }

        if (check()) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }

    }
    return 0;
}