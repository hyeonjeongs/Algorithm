#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
queue<int> que;
int bfs(int node){

    int number = 1;
    que.push(node);
    visited[node] = true;

    while(!que.empty()) {
        int next = que.front();
        que.pop();

        for(int i=0; i<graph[next].size(); i++) {
            if(!visited[graph[next][i]]) {
                visited[graph[next][i]] = true;
                que.push(graph[next][i]);
                number++;
            }
        }
    }
    return number;
}

int main() {
    int n, m;
    int maxs = 0;
    cin>>n>> m;
    vector<int> hack(n, 0);

    graph.assign(n+1, vector<int>(0));
    for(int i=0; i<m; i++) {
        int a, b;
        cin>> a>>b;
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        visited.assign(n+1,false);
        visited[i] = true;
        int tmp = bfs(i);
        hack[i-1] = tmp;
        maxs = max(maxs, tmp);
    }
    vector<int> result_number;
    for(int i=0; i<hack.size(); i++) {
        if(hack[i] == maxs){
            result_number.push_back(i+1);
        }
    }

    sort(result_number.begin(), result_number.end());
    for(int i=0; i<result_number.size(); i++) {
        cout << result_number[i] << ' ';
    }
    return 0;
}