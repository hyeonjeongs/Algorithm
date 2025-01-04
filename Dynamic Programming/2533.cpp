#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dp;
vector<vector<int>> node;
vector<bool> is_visited;

void dfs(int nodes) {
    is_visited[nodes] = true;
    dp[nodes][0] = 0; // 얼리 본인이 아니면 개수 0
    dp[nodes][1] = 1; // 본인이 얼리면 개수 1

    for(int i=0; i<node[nodes].size(); i++) {
        int child = node[nodes][i];
        if(is_visited[child]) {
            continue;
        }
        dfs(child);

        dp[nodes][0] += dp[child][1];
        dp[nodes][1] += min(dp[child][0], dp[child][1]);
    }
}

int main() {
    int n;
    cin >> n;
    dp.assign(n+1, vector<int>(2,0));
    node.assign(n+1, vector<int>());
    is_visited.assign(n+1, false);
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >>b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << '\n';

    return 0;
}