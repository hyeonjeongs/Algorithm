# include <iostream>
# include <vector>

using namespace std;
typedef pair<int, int> pi;
int main() {
    int n, k;
    cin >> n >> k;
    vector<pi> arr;
    for (int i=0; i<n; i++) {
        int w, v;
        cin >> w >> v;
        arr.push_back({w,v});
    }
    vector<int> dp(1e5+1, 0);

    for (int i=0; i<arr.size(); i++) {
        for (int j=k; j>=arr[i].first; j--) {
            dp[j] = max(dp[j], dp[j-arr[i].first] + arr[i].second);
        }
    }

    cout << dp[k] << '\n';

    return 0;
}