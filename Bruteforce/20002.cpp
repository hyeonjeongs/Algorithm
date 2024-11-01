#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<vector<long long>> total;
    long long result  = -1e9;

    total.assign(n+1, vector<long long>(n+1,0));
    vector<vector<long long>> sum(n+1, vector<long long>(n+1,0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++){
            cin >> total[i][j];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            sum[i][j] = total[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int m = min(n-i, n-j);
            for(int k=0; k<=m; k++) { // 여기서 k 0부터 해야함
                long long answer = sum[i+k][j+k] - sum[i-1][j+k] - sum[i+k][j-1] + sum[i-1][j-1];
                result = max(answer, result);
            }
        }
    }

    cout << result <<'\n';

    return 0;
}