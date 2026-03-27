# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

typedef pair<int, int> pi;
int main() {
    int n;
    cin >>n;
    vector<pi> consult(n+1);
    vector<int> dp(n+1, 0);
    for (int i=0; i<n; i++) {
        int t,p;
        cin >> t >> p;
        consult[i] = {t,p};
    }
    int maxs = 0;
    for (int i=0; i<=n; i++) {
        int index = i + consult[i].first;
        maxs = max(dp[i], maxs);
        dp[i] = maxs;
        if (index <= n) {
            int total = dp[i] + consult[i].second;
            dp[index] = max(total, dp[index]);
        }
    }
    cout << maxs << '\n';
    return 0;
}