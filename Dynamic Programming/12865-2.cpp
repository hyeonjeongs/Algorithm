#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
// 무게 k일 때 가치가 가장 높은 것
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(k+1, 0);
    vector<pi> weight(n,pi(0,0));


    for(int i=0; i<n; i++) {
        int v, w;
        cin >> w >> v;
        weight.push_back({w,v});
    }



    for(int i=0; i<weight.size(); i++) {
        for(int j=k; j>=weight[i].first; j--) {
            dp[j] = max(dp[j], dp[j-weight[i].first] + weight[i].second);
        }
    }

    cout << dp[k] << '\n';

    return 0;
}