#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> dp;
void countNum(int num) {
    dp[1][1] = 1;
    dp[2][1] = 1; dp[2][2]= 1;
    dp[3][1]=1; dp[3][2]=1; dp[3][3] =1;

    for (int i=4; i<=num; i++) {
        dp[i][1] = 1;
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
}

int main() {
    int t;
    dp.assign(10001, vector<int>(4, 0));
    cin>>t;
    vector<int> arr;
    int maxs =0;
    while (t--) {
        int num;
        cin >> num;
        arr.push_back(num);
        maxs = max(maxs, num);
    }
    countNum(maxs);
    for (int nums: arr) {
        cout << dp[nums][1] + dp[nums][2] + dp[nums][3] << '\n';
    }

    return 0;
}