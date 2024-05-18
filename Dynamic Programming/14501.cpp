#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, result = 0;
    cin >> n;

    vector<int> t(n+1, 0);
    vector<int> p(n+1, 0);
    vector<int> dp(n+1,0);

    for(int i=0; i<n; i++) {
        cin>> t[i]>> p[i];
    }

    int max_num = 0;
    for(int i=0; i<=n; i++) {
        int total = i + t[i];
        dp[i] = max(dp[i], max_num);
        if(total<=n) {
            dp[total] = max(dp[total], dp[i] + p[i]);
        }

        max_num = max(max_num, dp[i]);
    }
    cout<< max_num<< '\n';

    return 0;
}