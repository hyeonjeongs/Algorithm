#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int result;
void dfs(int node) {
    if(graph[node].size() <= 0) {
        return;
    }

    for(int i=0; i<graph[node].size(); i++) {
        if(!visited[graph[node][i]]){
            result++;
            visited[graph[node][i]] = true;
            dfs(graph[node][i]);
        }
    }
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
        result=0;
        visited[i] = true;
        dfs(i);
        hack[i-1] = result;
        maxs = max(maxs, result);
        
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
};