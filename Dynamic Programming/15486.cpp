# include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pi;
int main() {
    int n;
    cin >> n;
    vector<pi> arr;
    vector<int> dp(n+1,0);

    for (int i=0; i<n; i++) {
        int t,p;
        cin >> t >> p;
        arr.push_back({t,p});
    }

    for (int i=n-1; i>=0; i--) {
        int index = i + arr[i].first; // 정해진 시간 이후의 금액
        if (index>n) { // 여기 헤깔림 (index==n일때면 딱 n일째까지 한거임)
            dp[i] = dp[i+1];
        } else {
            dp[i] = max(dp[i+1], dp[index] + arr[i].second);
        }
    }
    cout << dp[0] << '\n';
}