#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    vector<int> dp(n+1, 1);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int maxs = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        maxs = max(maxs, dp[i]);
    }
    cout << maxs << '\n';

    return 0;
}