#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dp;
vector<bool> visited;
vector<vector<int>> node;

void dfs(int num) {
    visited[num] = true;
    dp[num][0] = 0;
    dp[num][1] = 1;

    for(int i=0; i< node[num].size(); i++) {
        int child = node[num][i];
        if(visited[child]) {
            continue;
        }
        dfs(child);
        dp[num][0] += dp[child][1];
        dp[num][1] += min(dp[child][0], dp[child][1]);
    }
}
int main() {
    int n;
    cin >> n;
    int u, v;
    node.assign(n+1, vector<int>());
    dp.assign(n+1, vector<int> (2, 0));
    visited.assign(n+1, false);
    for(int i=0; i<n; i++) {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << '\n';
    return 0;
}