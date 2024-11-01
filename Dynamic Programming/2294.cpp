/*
# include <iostream>
#include <vector>

using namespace std;
const int MAX = 10001;
int maxCount(vector<int> coin, int n, int k){
    vector<int> dp(k+1,MAX);

    dp[0] =0;
    for(int i=0; i<n; i++){
        for(int j=coin[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j-coin[i]] + 1);
        }
    }
    
    if(dp[k] == MAX){
        return -1;
    }


    return dp[k];
}

int main() {
    int n, k;

    cin>> n>> k;

    vector<int> coin(n,0);

    for(int i=0; i<n; i++){
        cin >> coin[i];
    }

    cout << maxCount(coin, n, k);

    return 0;
}*/

#include <iostream>
#include <vector>

#define MAX_SIZE 10001

using namespace std;

int main() {
    int n, k;
    cin >> n>> k;
    vector<int> coin(n, 0);

    for(int i=0; i<n; i++){
        cin >>coin[i];
    }

    vector<int> dp(k+1, MAX_SIZE);
    dp[0] = 0;

    for(int i=0; i<n; i++) {
        for(int j=coin[i]; j<=k; j++) {
            dp[j] = min(dp[j], dp[j-coin[i]]+1);
        }
    }

    if(dp[k] == 10001) {
        dp[k] = -1;
    }
    cout << dp[k];
    return 0;
}





















