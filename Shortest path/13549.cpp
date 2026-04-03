# include <iostream>
# include <vector>
# include <queue>
# define MAX 100001

using namespace std;
int n, k;
int moves[] = {2,1,-1};

vector<int> dp(MAX, 1e6);
void bfs() {
    queue<int> que;
    que.push(n);
    dp[n] = 0;
    while (!que.empty()) {
        int current = que.front();
        que.pop();
        for (int i=0; i<3; i++) {
            int next, time;
            if (i==0) {
                next = current * 2;
                time = 0;
            } else {
                next = current + moves[i];
                time = 1;
            }
            if (next>=0 && next <MAX && dp[next] > dp[current]+time) {
                dp[next] = dp[current] + time;
                que.push(next);
            }
        }
    }
}

int main() {
    cin >>n >> k;
    bfs();
    cout << dp[k] << '\n';
    return 0;
}