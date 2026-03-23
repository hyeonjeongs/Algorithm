#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> arr[i][j];
            dp[i][j]= dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
        }
    }
    while (m--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
    }

    return 0;
}


// #include <iostream>
// #include <vector>
//
// using namespace std;
//
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int n, m;
//     cin>>n>>m;
//
//     vector<vector<int>> arr(n+1, vector<int>(n+1,0));
//     vector<vector<int>> dp(n+1, vector<int>(n+1,0));
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=n; j++){
//             cin>> arr[i][j];
//             dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + arr[i][j];
//         }
//     }
//
//     for(int i=0; i<m; i++) {
//
//         int a, b, c,d;
//         cin>>a>>b>>c>>d;
//
//         int result = dp[c][d] - dp[a-1][d] - dp[c][b-1] + dp[a-1][b-1];
//         cout<< result<<'\n';
//     }
//
//     return 0;
// }